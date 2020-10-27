#include "../header/minishell.h"

void        ft_do_actions(t_data *data)
{
    
    ft_reverse_actions(data);
    int i = 0;
    while (data->cmd_tab && data->cmd_tab[i])
    {
        printf("**********%d*************\n", i);
        ft_print_cmd(data->cmd_tab[i]);
        ++i;
    }
    //ft_echo(data);
    //ft_check_redirections(data->cmd, data->path);
    
    ft_fork(data);
    //ft_pwd(data);
    //ft_env(data);
    //ft_exit(data);
}