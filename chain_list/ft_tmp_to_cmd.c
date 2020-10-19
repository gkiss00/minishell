#include "../header/minishell.h"

static t_cmd    *ft_fill_arg(t_cmd *cmd, t_cmd *tmp)
{
    int     i;

    i = 0;
    while(cmd != NULL && (cmd ->type != 0 && cmd->type != 1))
    {
        while(cmd->arg && cmd->arg[i])
        {
            tmp->arg = ft_add_to_tab(tmp->arg, cmd->arg[i]);
            ++i;
        }
        ft_free_tab2(cmd->arg);
        cmd->arg = NULL;
        cmd = cmd->next;
    }
    return (cmd);
}

static void     ft_get_arg(t_cmd *cmd)
{
    t_cmd *tmp;

    while(cmd != NULL)
    {
        if (cmd->type == 1 || cmd->type == 0)
            tmp = cmd;
        cmd = cmd->next;
        cmd = ft_fill_arg(cmd, tmp);
    }
}

static t_tmp    *ft_fill_cmd(t_cmd *cmd, t_tmp *tmp, int t)
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
    return (tmp);
}

static t_cmd    *ft_get_cmd(t_tmp *tmp)
{
    int     i;
    int     t;
    t_cmd   *c;
    t_cmd   *save_cmd;

    i = 0;
    save_cmd = NULL;
    while(tmp != NULL)
    {
        if (tmp->type != 0 || i == 0)
            c = ft_cmd_new();
        t = tmp->type;
        if (tmp->type != 0)
            tmp = tmp->next;
        tmp = ft_fill_cmd(c, tmp, t);
        ft_cmd_add_back(&save_cmd, c);
        ++i;
    }
    return (save_cmd);
}

t_cmd           *ft_tmp_to_cmd(t_tmp *tmp)
{
    t_cmd   *cmd;

    cmd = NULL;
    cmd = ft_get_cmd(tmp);
    ft_get_arg(cmd);
    return (cmd);
}