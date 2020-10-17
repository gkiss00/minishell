#include "../header/minishell.h"

static int          ft_get_commandes(t_data *data, int i)
{
    t_tmp   *tmp;

    tmp = NULL;
    if ((data->tab_tmp = ft_sp_split(data->tabinput[i], ' ')) == NULL)
        return (ft_free_error(data));
    tmp = ft_tab_to_tmp(data->tab_tmp);
    data->cmd = ft_tmp_to_cmd(tmp);
    ft_print_cmd(data->cmd);
    ft_free_cmd(data->cmd);
    ft_free_tmp(tmp);
    return (1);
}

void                ft_get_actions(t_data *data, int i)
{
    ft_get_commandes(data, i);
}