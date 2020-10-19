#include "../header/minishell.h"

void        ft_do_actions(t_data *data)
{
    execve("/bin/grep", data->env, data->env);
    //ft_pwd(data);
    //ft_env(data);
    ft_exit(data);
}