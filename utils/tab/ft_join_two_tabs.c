/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_two_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:42:19 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char		**ft_join_two_tabs(char **t1, char **t2)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (t1 == NULL || t2 == NULL)
		return (NULL);
	new_tab = ft_copy_tab(t1);
	while (t2[i] != NULL)
	{
		new_tab = ft_add_to_tab(new_tab, t2[i]);
		++i;
	}
	return (new_tab);
}
