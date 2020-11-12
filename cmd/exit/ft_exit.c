#include "../../header/minishell.h"

static int  ft_is_arg_valid(t_data *data, char *arg)
{
    int i;

    i = 0;
    while (arg[i] != '\0' && (arg[i] == '-' || arg[i] == '+'))
        ++i;
    while (arg[i] != '\0')
    {
        if (ft_isdigit(arg[i]) != 1)
        {
            ft_error(data, arg, EXIT);
            return (0);
        }
        ++i;
    }
    return (1);
}

void        ft_exit(t_data *data)
{
    int ret;

    if (data->cmd_tab[data->a]->arg == NULL)
        ret = 0;
    else
    {
        if (data->cmd_tab[data->a]->arg[0] == NULL)
            ret = 0;
        else if (data->cmd_tab[data->a]->arg[1] == NULL)
        {
            if (ft_is_arg_valid(data, data->cmd_tab[data->a]->arg[0]) == 0)
                ret = 255;
            else
                ret = ft_atoi(data->cmd_tab[data->a]->arg[0]);
        }
        else
        {
            ft_putstr_fd("minishell: exit: too many arguments\n", 2);
            data->last_output = 1;
            return ;
        }
    }
    ft_free_data(data);
    exit(ret);
}