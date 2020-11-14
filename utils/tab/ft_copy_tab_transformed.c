/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab_transformed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:41:05 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char		**ft_copy_tab_transformed(char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	if (tab == NULL)
		return (NULL);
	tmp = malloc(sizeof(char *) * (get_length(tab) + 1));
	if (tmp == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		if ((tmp[i] = ft_transform(tab[i])) == NULL)
		{
			ft_free_tab2(tmp);
			return (NULL);
		}
		++i;
	}
	tmp[i] = NULL;
	return (tmp);
}
