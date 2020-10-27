#include "../header/minishell.h"

static int  ft_get_lenght_cmd_tab(t_data *data)
{
    int     i;

    i = 0;
    while(data->cmd_tab && data->cmd_tab[i])
    {
        ++i;
    }
    return (i);
}

void        ft_reverse_actions(t_data *data)
{
    int     i;
    int     size;
    t_cmd   *cmd;

    i = 0;
    size = ft_get_lenght_cmd_tab(data);
    cmd = NULL;
    while(i < size / 2)
    {
        cmd = data->cmd_tab[i];
        data->cmd_tab[i] = data->cmd_tab[size - 1 - i];
        data->cmd_tab[size - 1 - i] = cmd;
        ++i;
    }
}