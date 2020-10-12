#include "../header/minishell.h"

void        ft_free_tmp(t_tmp *tmp)
{
    t_tmp *next;

    while (tmp != NULL)
    {
        next = tmp->next;
        ft_free_tab1(tmp->str);
        free(tmp);
        tmp = next;
    }
}