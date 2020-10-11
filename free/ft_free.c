#include "../header/minishell.h"

void        ft_free_tab2(char **tab)
{
    int     i;

    i = 0;
    if (!tab)
        return ;
    while(tab[i] != NULL)
    {
        free(tab[i]);
        ++i;
    }
    free(tab);
}

void        ft_free_tab1(char *str)
{
    if (str)
        free(str);
}