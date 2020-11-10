#include "../header/minishell.h"

void     ft_hub(t_data *data, char *cmd)
{
    char    *cmd_maj;

    cmd_maj = ft_tomaj(cmd);
    if (ft_strcmp(cmd, "exit") == 0)
        ft_export(data);
    if (ft_strcmp(cmd, "export") == 0)
        ft_export(data);
    if (ft_strcmp(cmd, "unset") == 0)
        ft_export(data);
    if (ft_strcmp(cmd, "cd") == 0)
        ft_export(data);
    if (ft_strcmp(cmd_maj, "ECHO") == 0)
        ft_echo(data);
    if (ft_strcmp(cmd_maj, "PWD") == 0)
        ft_echo(data);
    if (ft_strcmp(cmd_maj, "ENV") == 0)
        ft_echo(data);
}