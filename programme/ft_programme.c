#include "../header/minishell.h"

void        ft_programme(t_data *data)
{
    int     i;

    i = 0;
    if (ft_get_input(data) == -1)
        return ;
    while(data->tabinput[i] != NULL)
    {
        puts(data->tabinput[i]);
        ft_get_actions(data, i);
        ++i;
    }
    
}