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
    data->gnl_line = NULL;
    ft_free_tab1(data->gnl_tmp);
    data->gnl_tmp = NULL;
    ft_free_tab2(data->tabinput);
    data->tabinput = NULL;
    ft_free_tab2(data->tab_tmp);
    data->tab_tmp = NULL;
    ft_free_tab2(data->env);
    data->env = NULL;
    ft_free_tab1(data->path);
    data->path = NULL;
    ft_free_cmd(data->cmd);
    data->cmd = NULL;
    if (data->cmd_tab != NULL)
        free(data->cmd_tab);
    data->cmd_tab = NULL;
    free(data);
}