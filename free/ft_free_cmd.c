#include "../header/minishell.h"

void        ft_free_cmd(t_cmd *cmd)
{
    t_cmd *next;

    while (cmd != NULL)
    {
        next = cmd->next;
        ft_free_tab1(cmd->cmd);
        ft_free_tab2(cmd->arg);
        free(cmd);
        cmd = next;
    }
}