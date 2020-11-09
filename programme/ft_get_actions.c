#include "../header/minishell.h"

static void         ft_cut(t_data *data)
{
    t_cmd   *save;
    t_cmd   *tmp;

    tmp = NULL;
    save = data->cmd;
    while(data->cmd != NULL)
    {
        if(data->cmd->next != NULL && data->cmd->next->type == 1)
        {
            tmp = data->cmd;
            data->cmd = data->cmd->next;
            tmp->next = NULL;
        }
        else
            data->cmd = data->cmd->next;
    }
    data->cmd = NULL;
}

static int          get_nb_pipe(t_cmd *cmd)
{
    int     nb;

    nb = 1;
    while(cmd != NULL)
    {
        if (cmd->type == 1)
            ++nb;
        cmd = cmd->next;
    }
    return (nb);
}

static int          ft_devide_commandes(t_data *data)
{
    int     i;
    t_cmd   *save;
    t_cmd   *tmp;

    i = 0;
    tmp = data->cmd;
    save = data->cmd;
    data->cmd_tab = malloc(sizeof(t_cmd*) * get_nb_pipe(data->cmd) + 1);
    if (data->cmd_tab == NULL)
        return(ft_error(NULL, MALLOC));
    while(i < get_nb_pipe(save))
    {
        data->cmd_tab[i] = tmp;
        ++i;
        while(data->cmd != NULL && data->cmd->type != 1)
            data->cmd = data->cmd->next;
        
        tmp = data->cmd;
        if (data->cmd != NULL)
            data->cmd = data->cmd->next;
    }
    data->cmd_tab[i] = NULL;
    data->cmd = save;
    return (0);
}

static int          ft_get_commandes(t_data *data, int i)
{
    t_tmp   *tmp;

    tmp = NULL;
    if ((data->tab_tmp = ft_sp_split(data->tabinput[i], ' ')) == NULL)
        return (ft_free_error(data));
    tmp = ft_tab_to_tmp(data->tab_tmp);
    data->cmd = ft_tmp_to_cmd(tmp);
    ft_free_tmp(tmp);
    return (1);
}

void                ft_get_actions(t_data *data, int i)
{
    ft_get_commandes(data, i);
    ft_devide_commandes(data);
    ft_cut(data);
    ft_check_options_echo(data);
    ft_check_var_env(data);
    ft_transform_all(data);
    ft_print_cmd(data->cmd_tab[0]);
}