#include "../header/minishell.h"
/*
static int         ft_is_redirection(char *str)
{
    if (ft_strcmp(str, "|") == 0)
        return (1);
    if (ft_strcmp(str, "<") == 0)
        return (1);
    if (ft_strcmp(str, ">") == 0)
        return (1);
    if (ft_strcmp(str, ">>") == 0)
        return (1);
    return (-1);
}

static int          ft_fill_arg(t_data *data, int i)
{
    while(data->tab_tmp[i] != NULL)
    {
        ft_add_to_tab(data->cmd->arg, data->tab_tmp[i]);
        ++i;
    }
    return (1);
}
*/
static int                 ft_set_cmd(t_data *data)
{
    int     i;

    i = 0;
    while(data->tab_tmp[i])
    {
        ++i;
    }
    return (1);
}

static int          ft_get_commandes(t_data *data, char *input)
{
    if ((data->tab_tmp = ft_sp_split(input, ' ')) == NULL)
    {
        return (ft_free_error(data));
    }
    if (ft_set_cmd(data) == -1)
    {
        return (ft_free_error(data));
    }
    return (1);
}

void                ft_do_actions(t_data *data)
{
    int     i;

    i = 0;
    if (!data->tabinput)
        return ;
    while (data->tabinput[i] != NULL)
    {
        if (ft_get_commandes(data, data->tabinput[i]) == -1)
            return ;
        ++i;
    }
}