# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <unistd.h>

//https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file
//int fdfd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
extern char         **environ;

int     main()
{
    pid_t   pid;
    char    *path[3];
    path[0] = "/bin/ls";
    path[1] = "/users/kissgautier/desktop/minishell";
    path[2] = NULL;
    char    *hub = "hub";
    char    buff[10];
    int     pipefd[2];
    int     ret;
    
    int     fd1 = open("test1.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    int     fd2 = open("test2.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    
    pipe(pipefd);
    
    pid = fork();
    if (pid < 0)
    {
        printf("error\n");
    }
    else if (pid == 0)
    {
        close(pipefd[0]);    // close reading end in the child

        dup2(pipefd[1], 1);  // send stdout to the pipe
        dup2(pipefd[1], 2);  // send stderr to the pipe

        close(pipefd[1]);
        dup2(fd1, 1);
        execve("/bin/ls", path, environ);
        printf("child\n");
        
        exit(0);
    }
    else
    {
        printf("parent waiting\n");
        wait(NULL);
        //execve("/bin/grep", &tmp, environ);
    }
}