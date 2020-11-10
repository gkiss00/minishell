#include "../../header/minishell.h"

static void ft_print_env(t_data *data)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    while(data->env && data->env[i])
    {
        tmp = ft_sub_after_char(data->env[i], '=');
        if (tmp && ft_strcmp(tmp, "") != 0)
        {
            ft_putstr_fd(data->env[i], 1);
            ft_putstr_fd("\n", 1);
        }
        free(tmp);
        ++i;
    }
}

void        ft_env(t_data *data)
{
    if (get_length(data->cmd_tab[data->a]->arg) != 0)
        ft_error(NULL, NO_FILE_OR_DIR);
    else
        ft_print_env(data);
}