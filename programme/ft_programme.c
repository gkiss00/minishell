#include "../header/minishell.h"

static void reset(t_data *data)
{
    ft_free_cmd(data->cmd);
    data->cmd = NULL;
}

void        ft_programme(t_data *data)
{
    int     i;

    i = 0;
    if (ft_get_input(data) == -1)
        return ;
    if (ft_check_input(data) == -1)
    {
        ft_free_tab2(data->tabinput);
        data->tabinput = NULL;
        return ;
    }   
    while(data->tabinput[i] != NULL)
    {
        ft_get_actions(data, i);
        ft_do_actions(data);
        reset(data);
        ++i;
    }
    ft_free_tab2(data->tabinput);
    data->tabinput = NULL;
}