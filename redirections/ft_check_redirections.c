#include "../header/minishell.h"

int     ft_check_redirections(t_cmd *cmd)
{
    t_cmd   *save;

    save = cmd;
    while (cmd != NULL && cmd->type != 1)
    {
        if (cmd->type)
        cmd = cmd->next;
    }
}