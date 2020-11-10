#include "../header/minishell.h"

void     ft_hub(t_data *data, char *cmd)
{
    char    *cmd_maj;

    cmd_maj = NULL;
    if (ft_strcmp(cmd, "exit") == 0)
        ft_exit(data);
    else if (ft_strcmp(cmd, "export") == 0)
        ft_export(data);
    else if (ft_strcmp(cmd, "unset") == 0)
        ft_unset(data);
    else if (ft_strcmp(cmd, "cd") == 0)
        ft_cd(data);
    cmd_maj = ft_tomaj(cmd);
    if (ft_strcmp(cmd_maj, "ECHO") == 0)
        ft_echo(data);
    else if (ft_strcmp(cmd_maj, "PWD") == 0)
        ft_pwd(data);
    else if (ft_strcmp(cmd_maj, "ENV") == 0)
        ft_env(data);
    free(cmd_maj);
}