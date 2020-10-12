#include "../header/minishell.h"

void        ft_print_tab(char **tab)
{
    int i;

    i = 0;
    if (tab == NULL)
        return;
    while(tab[i] != NULL)
    {
        ft_putstr_fd(tab[i], 1);
        ft_putstr_fd("\n", 1);
        ++i;
    }
}