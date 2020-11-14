/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:40:33 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int			get_length(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		++i;
	return (i);
}

static int	add_last(char **tab, char **new_tab, char *str, int i)
{
	new_tab[i] = ft_strdup(str);
	if (new_tab[i] == NULL)
	{
		ft_free_tab2(tab);
		ft_free_tab2(new_tab);
		return (-1);
	}
	return (1);
}

char		**ft_add_to_tab(char **tab, char *str)
{
	int		i;
	char	**new_tab;

	i = 0;
	if ((new_tab = malloc(sizeof(char *) * (get_length(tab) + 2))) == NULL)
		return (NULL);
	while (tab != NULL && tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (new_tab[i] == NULL)
		{
			ft_free_tab2(tab);
			ft_free_tab2(new_tab);
			return (NULL);
		}
		++i;
	}
	add_last(tab, new_tab, str, i);
	new_tab[i + 1] = NULL;
	ft_free_tab2(tab);
	return (new_tab);
}
