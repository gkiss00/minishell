#include "../header/minishell.h"

void        ft_free_cmd2(t_cmd **cmd)
{
    int     i;

    i = 0;
    if (cmd)
    {
        while(cmd[i] != NULL)
        {
            ft_free_cmd(cmd[i]);
            ++i;
        }
        free(cmd);
    }
}

void        ft_free_tab2(char **tab)
{
    int     i;

    i = 0;
    if (tab == NULL)
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

int         ft_free_int(char *str)
{
    free(str);
    return (1);
}