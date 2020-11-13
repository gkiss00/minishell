#include "../header/minishell.h"

void        ft_do_actions(t_data *data)
{
    ft_reverse_actions(data);
    ft_fork(data);
}