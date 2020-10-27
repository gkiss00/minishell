#include "../header/minishell.h"

void        ft_do_actions(t_data *data)
{
    data->i3 = 0;
    ft_echo(data);
    ft_check_redirections(data->cmd, data->path);
    //ft_pwd(data);
    //ft_env(data);
    //ft_exit(data);
}