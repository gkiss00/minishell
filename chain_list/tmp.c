/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:27:31 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void		ft_print_tmp(t_tmp *head)
{
	t_tmp	*save;

	save = head;
	while (head != NULL)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(head->str, 1);
		ft_putstr_fd("\n", 1);
		ft_putnbr_fd(head->type, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
	}
	head = save;
}

void		ft_tmp_add_back(t_tmp **head, t_tmp *new)
{
	t_tmp	*last;

	if (head)
	{
		if (*head)
		{
			last = ft_tmp_last(*head);
			last->next = new;
		}
		else
			*head = new;
	}
}

t_tmp		*ft_tmp_last(t_tmp *head)
{
	while (head)
	{
		if (!head->next)
			return (head);
		head = head->next;
	}
	return (head);
}

t_tmp		*ft_tmp_new(void)
{
	t_tmp	*new;

	new = malloc(sizeof(t_tmp));
	if (new == NULL)
		return (NULL);
	new->str = NULL;
	new->type = 0;
	new->next = NULL;
	return (new);
}
