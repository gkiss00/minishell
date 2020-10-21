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
    char    *path = "/users/kissgautier/Desktop/minishell";
    char    *hub = "hub";
    char    buff[10];
    
    pid = fork();
    if (pid < 0)
    {

    }
    else if (pid == 0)
    {
        char buff[10];

        int fd = open("test.txt", O_CREAT | O_RDONLY | O_WRONLY, S_IRUSR | S_IWUSR);
        dup2(fd, 1);
        dup2(fd, 2);
        close(fd);
        execve("/bin/cat", &path, environ);
        exit(0);
    }

}