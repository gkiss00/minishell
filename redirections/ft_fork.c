#include "../header/minishell.h"

static void ft_read_output(t_data *data, int pipefd[2])
{
    int     ret;
    char    buff[10];
    char    *str;

    str = NULL;
    while((ret = read(pipefd[0], buff, 9)) > 0)
    {
        buff[9] = '\0';
        str = ft_strjoin_free(str, buff, 1);
    }
    data->readed = str;
}

static void ft_parent(t_data *data, int pipefd[2])
{
    close(pipefd[1]);
    wait(NULL);
    //printf("je suis parent : %d\n", data->a);
    ft_read_output(data, pipefd);
    if (ft_check_redirections(data->cmd_tab[data->a], data->path) == -1)
        return ;
    //ft_do_redirections(data);
    close(pipefd[0]);
    ft_hub(data, data->cmd_tab[data->a]->cmd);
}

static void ft_child(t_data *data, int pipefd[2])
{
    close(pipefd[0]);
    dup2(pipefd[1], 1);
    close(pipefd[1]);
    //printf("je suis enfant : %d\n", data->a);
    ++data->a;
    if(!data->cmd_tab[data->a])
        exit(0);
    else
        ft_fork(data);
}

int         ft_fork(t_data *data)
{
    pid_t   pid;
    int     pipefd[2];

    //puts("fork");
    pipe(pipefd);
    pid = fork();
    if (pid < 0)
        return(ft_error(NULL, FORK));
    else if (pid == 0)
    {
        ft_child(data, pipefd);
        ft_free_data(data);
        exit(0);
    }
    else
    {
        ft_parent(data, pipefd);
    }
    return (0);
}