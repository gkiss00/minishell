#include "../header/minishell.h"

void        ft_print_cmd(t_cmd *head)
{
    t_cmd   *save;

    save = head;
    while (head != NULL)
    {
        ft_putstr_fd("\n", 1);
        ft_putstr_fd("cmd : ", 1);
        ft_putstr_fd(head->cmd, 1);
        ft_putstr_fd("\n", 1);
        ft_putstr_fd("arg : ", 1);
        ft_print_tab(head->arg);
        ft_putnbr_fd(head->type, 1);
        ft_putstr_fd("\n", 1);
        ft_putnbr_fd(head->opt, 1);
        ft_putstr_fd("\n", 1);
        head = head->next;
    }
    head = save;
}

void        ft_cmd_add_back(t_cmd **head, t_cmd *new)
{
    t_cmd	*last;

	if (head)
	{
		if (*head)
		{
			last = ft_cmd_last(*head);
			last->next = new;
		}
		else
			*head = new;
	}
}

t_cmd       *ft_cmd_last(t_cmd *head)
{
    while (head)
	{
		if (!head->next)
			return (head);
		head = head->next;
	}
	return (head);
}

t_cmd       *ft_cmd_new()
{
    t_cmd *new;

    if ((new = malloc(sizeof(t_cmd))) == NULL)
        return (NULL);
    new->cmd = NULL;
    new->arg = NULL;
    new->type = 0;
    new->opt = 0;
    new->next = NULL;
    return (new);
}