#include "../header/minishell.h"

void        ft_free_tmp_data(t_data *data)
{
    ft_free_tab1(data->tmp);
    data->tmp = NULL;
	ft_free_tab2(data->tab_tmp);
	data->tab_tmp = NULL;
}

void        ft_free_data(t_data *data)
{
    if (!data)
        return ;
    ft_free_tab1(data->gnl_line);
    ft_free_tab1(data->gnl_tmp);
    ft_free_tab2(data->tabinput);
    ft_free_tab2(data->tab_tmp);
    ft_free_tab2(data->env);
    ft_free_tab1(data->path);
    ft_free_cmd(data->cmd);
    free(data);
}