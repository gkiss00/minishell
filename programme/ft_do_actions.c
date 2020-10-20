#include "../header/minishell.h"

void        ft_do_actions(t_data *data)
{
    char    *p =  ft_get_path(data->path, data->cmd->arg[0]);
    puts(p);
    free(p);
    //ft_pwd(data);
    //ft_env(data);
    ft_exit(data);
    
}