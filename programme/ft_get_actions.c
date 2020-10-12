#include "../header/minishell.h"

static int          ft_find_type(char *str)
{
    if (ft_strcmp(str, "|") == 0)
        return (1);
    if (ft_strcmp(str, "<") == 0)
        return (2);
    if (ft_strcmp(str, ">") == 0)
        return (3);
    if (ft_strcmp(str, ">>") == 0)
        return (4);
    return (0);
}

static void         ft_fill_tmp(t_tmp *tmp, char *str)
{
    tmp->str = ft_strdup(str);
    tmp->type = ft_find_type(str);
}

static t_tmp        *ft_get_tmp(t_tmp *head, char **tab)
{
    int     i;
    t_tmp   *tmp;
    t_tmp   *save;

    i = 0;
    tmp = NULL;
    while(tab[i] != NULL)
    {
        tmp = ft_tmp_new();
        if (i == 0)
            save = tmp;
        ft_fill_tmp(tmp, tab[i]);
        ft_tmp_add_back(&head, tmp);
        ++i;
    }
    return (save);
}

static int          ft_get_commandes(t_data *data, int i)
{
    char    **tab_tmp1;
    t_tmp   *tmp;

    tab_tmp1 = NULL;
    tmp = NULL;
    if ((data->tab_tmp = ft_sp_split(data->tabinput[i], ' ')) == NULL)
        return (ft_free_error(data));
    tmp = ft_get_tmp(tmp, data->tab_tmp);
    ft_print_tmp(tmp);
    ft_free_tmp(tmp);
    tab_tmp1 = ft_copy_tab_transformed(data->tab_tmp);
    ft_free_tab2(tab_tmp1);
    return (1);
}

void                ft_get_actions(t_data *data, int i)
{
    ft_get_commandes(data, i);
}