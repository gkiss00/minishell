#include "../header/minishell.h"

static void reset(t_data *data)
{
    data->cmd = NULL;
    ft_free_cmd2(data->cmd_tab);
    data->cmd_tab = NULL;
    ft_free_tab1(data->readed);
    data->readed = NULL;
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
    if (output_ctrls != -1)
    {
        data->last_output = output_ctrls;
        output_ctrls = -1;
    }
    // system("leaks minishell");
}