#include "../../header/minishell.h"

void        ft_exit(t_data *data)
{
    ft_free_data(data);
    exit(0);
}