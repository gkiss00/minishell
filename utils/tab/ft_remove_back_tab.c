#include "../../header/minishell.h"

static int  get_size(char **tab)
{
    int size;

    size = get_length(tab);
    if (size == 0)
        size = 1;
    return (size);
}

char    **ft_remove_back_tab(char **tab)
{
    int     i;
    int     size;
    char    **new_tab;

    i = 0;
    size = get_size(tab);
    if (tab == NULL)
        return (NULL);
    new_tab = malloc(sizeof(char*) * size);
    if (new_tab == NULL)
        return (NULL);
    while(tab[i] != NULL && i < get_length(tab) - 1)
    {
        if ((new_tab[i] = ft_strdup(tab[i])) == NULL)
        {
            ft_free_tab2(new_tab);
            return (tab);
        }
        ++i;
    }
    new_tab[i] = NULL;
    ft_free_tab2(tab);
    return (new_tab);
}