#include "../../header/minishell.h"

void        ft_echo(t_data *data)
{
    int     i;

    i = 0;
    while(data->cmd_tab && data->cmd_tab[0] && data->cmd_tab[0]->arg && data->cmd_tab[0]->arg[i])
    {
        ft_putstr_fd(data->cmd_tab[0]->arg[i], 1);
        if (data->cmd_tab[0]->arg[i + 1])
        ft_putstr_fd(" ", 1);
        ++i;
    }
    if (data->cmd_tab && data->cmd_tab[0] && data->cmd_tab[0]->opt == 0)
        ft_putstr_fd("\n", 1);
}