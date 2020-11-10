#include "../../header/minishell.h"

void        ft_pwd(t_data *data)
{
    ft_putstr_fd(data->path, 1);
    ft_putstr_fd("\n", 1);
}