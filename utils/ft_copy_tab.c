#include "../header/minishell.h"

char        **ft_copy_tab(char **tab)
{
    int     i;
    char    **tmp;

    i = 0;
    tmp = malloc(sizeof(char *) * (get_length(tab) + 1));
    if(tmp == NULL)
        return (NULL);
    while(tab[i] != NULL)
    {
        if((tmp[i] = ft_strdup(tab[i])) == NULL)
        {
            ft_free_tab2(tmp);
            return (NULL);
        }
        ++i;
    }
    return (tmp);
}