#include "../header/minishell.h"

static void ft_parent(t_data *data)
{
    wait(NULL);
    printf("je suis parent : %d\n", data->cmd_act);
}

static void ft_child(t_data *data)
{
    
    printf("je suis enfant : %d\n", data->cmd_act);
    ++data->cmd_act;
    if(!data->cmd_tab[data->cmd_act])
        exit(0);
    else
        ft_fork(data);
}

int         ft_fork(t_data *data)
{
    pid_t   pid;

    puts("fork");
    pid = fork();
    if (pid < 0)
        return(ft_error(NULL, FORK));
    else if (pid == 0)
    {
        ft_child(data);
        ft_free_data(data);
        exit(0);
    }
    else
    {
        ft_parent(data);
    }
    return (0);
}