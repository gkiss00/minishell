/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_tmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:29:09 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int			ft_find_type(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (1);
	if (ft_strcmp(str, "<") == 0)
		return (2);
	if (ft_strcmp(str, ">") == 0)
		return (3);
	if (ft_strcmp(str, ">>") == 0)
		return (4);
	return (0);
}

static void			ft_fill_tmp(t_tmp *tmp, char *str)
{
	tmp->str = ft_strdup(str);
	tmp->type = ft_find_type(str);
}

static t_tmp		*ft_get_tmp(t_tmp *head, char **tab)
{
	int		i;
	t_tmp	*tmp;
	t_tmp	*save;

	i = 0;
	tmp = NULL;
	save = NULL;
	while (tab[i] != NULL)
	{
		if ((tmp = ft_tmp_new()) == NULL)
		{
			ft_free_tmp(save);
			return (NULL);
		}
		if (i == 0)
			save = tmp;
		ft_fill_tmp(tmp, tab[i]);
		ft_tmp_add_back(&head, tmp);
		++i;
	}
	return (save);
}

t_tmp				*ft_tab_to_tmp(char **str)
{
	t_tmp	*tmp;

	tmp = NULL;
	tmp = ft_get_tmp(tmp, str);
	return (tmp);
}
