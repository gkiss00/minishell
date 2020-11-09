#include "../../header/minishell.h"

void        ft_env(t_data *data)
{
    if (get_length(data->cmd_tab[data->a]->arg) != 0)
        ft_error(NULL, NO_FILE_OR_DIR);
    ft_print_tab(data->env);
}