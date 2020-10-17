#include "../header/minishell.h"

static void     ft_fill_cmd(t_cmd *cmd, t_tmp *tmp, int t)
{
    int     i;

    i = 0;
    cmd->type = t;
    while(tmp != NULL && tmp->type == 0)
    {
        if (i == 0)
            cmd->cmd = ft_strdup(tmp->str);
        else
            cmd->arg = ft_add_to_tab(cmd->arg, tmp->str);
        tmp = tmp->next;
        ++i;
    }
}

static t_cmd    *ft_get_cmd(t_tmp *tmp)
{
    int     i;
    int     t;
    t_tmp   *save_tmp;
    t_cmd   *c;
    t_cmd   *save_cmd;

    i = 0;
    save_tmp = tmp;
    save_cmd = NULL;
    while(tmp != NULL)
    {
        if (tmp->type != 0 || i == 0)
            c = ft_cmd_new();
        if (tmp->type != 0)
        {
            t = tmp->type;
            tmp = tmp->next;
        }
        ft_fill_cmd(c, tmp, t);
        ft_cmd_add_back(&save_cmd, c);
        ft_print_cmd(save_cmd);
        ++i;
    }
    tmp = save_tmp;
    return (save_cmd);
}

t_cmd           *ft_tmp_to_cmd(t_tmp *tmp)
{
    t_cmd   *cmd;

    cmd = NULL;
    cmd = ft_get_cmd(tmp);
    ft_free_tmp(tmp);
    return (cmd);
}