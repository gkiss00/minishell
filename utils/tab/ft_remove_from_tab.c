#include "../../header/minishell.h"

static int  get_size(char **tab)
{
    int size;

    size = get_length(tab);
    if (size == 0)
        size = 1;
    return (size);
}

char    **ft_remove_from_tab(char **tab, int index)
{
    int     i;
    int     j;
    char    **new_tab;

    i = -1;
    j = -1;
    if (tab == NULL || index < 0 || index > get_length(tab) - 1)
        return (tab);
    if ((new_tab = malloc(sizeof(char*) * get_size(tab))) == NULL)
        return (NULL);
    while(tab[++i] != NULL && i < get_length(tab) - 1)
    {
        if (i != index)
        {
            if ((new_tab[++j] = ft_strdup(tab[i])) == NULL)
            {
                ft_free_tab2(new_tab);
                return (tab);
            }
        }
    }
    new_tab[j] = NULL;
    ft_free_tab2(tab);
    return (new_tab);
}