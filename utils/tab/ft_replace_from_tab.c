#include "./../../header/minishell.h"

char        **ft_replace_from_tab(char **tab, char *str, int index)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = NULL;
    if (tab == NULL || index >= get_length(tab) || index < 0)
        return(tab);
    while(tab[i])
    {
        if (i == index)
        {
            if ((tmp = ft_strdup(str)) == NULL)
                return (tab);
            free(tab[i]);
            tab[i] = tmp;
            return (tab);
        }
        ++i;
    }
    return (tab);
}