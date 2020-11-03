#include "./../header/minishell.h"

static void ft_replace_env(t_cmd *cmd, char **env)
{
    int     i;
    int     index;
    char    *tmp;

    i = 0;
    while(cmd->arg && cmd->arg[i])
    {
        index = ft_find_in_env(env, cmd->arg[i]);
        if(index != -1)
        {
            tmp = ft_return_good_env(env, index);
            cmd->arg = ft_replace_from_tab(cmd->arg, tmp, i);
        }    
    }
}

static void ft_check_var_env_cmd(t_cmd* cmd, char **env)
{
    while(cmd)
    {
        ft_replace_env(cmd, env);
        cmd = cmd->next;
    }
}

void        ft_check_var_env(t_data* data)
{
    int     i;

    i = 0;
    while(data->cmd_tab && data->cmd_tab[i])
    {
        ft_check_var_env_cmd(data->cmd_tab[i], data->env);
        ++i;
    }
}