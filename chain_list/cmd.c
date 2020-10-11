#include "../header/minishell.h"

void        ft_add_back(t_cmd *head, t_cmd *last)
{
    int     i;
    t_cmd   *tmp;

    tmp = head;
    i = 0;
    if (head == NULL)
    {
        head = last;
        return ;
    }
    while(head->next != NULL)
    {
        head = head->next;
        ++i;
    }
    head->next = last;
    head = tmp;
}

t_cmd       *ft_new()
{
    t_cmd *new;

    if ((new = malloc(sizeof(t_cmd))) == NULL)
        return (NULL);
    new->cmd = NULL;
    new->arg = NULL;
    new->type = 0;
    new->next = NULL;
    return (new);
}