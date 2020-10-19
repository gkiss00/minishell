#include "../../header/minishell.h"

void        ft_pwd(t_data *data)
{
    ft_putstr_fd(data->path, data->fd);
    ft_putstr_fd("\n", data->fd);
}