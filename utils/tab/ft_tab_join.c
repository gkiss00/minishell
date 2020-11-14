/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:45:34 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	get_size(char **tab, char *str)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		size += ft_strlen(tab[i]);
		++i;
	}
	size += (ft_strlen(str) * get_length(tab));
	return (size);
}

static void	ft_copy(char **tab, char *str, char **joined)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < get_size(tab, str))
	{
		k = 0;
		while (str && str[k] != '\0')
		{
			joined[0][i] = str[k++];
			++i;
		}
		k = 0;
		while (tab && tab[j] && tab[j][k] != '\0')
		{
			joined[0][i] = tab[j][k++];
			++i;
		}
		++j;
	}
	joined[0][i] = '\0';
}

char		*ft_tab_join(char **tab, char *str)
{
	char	*joined;

	if (tab == NULL || str == NULL)
		return (NULL);
	if ((joined = malloc(get_size(tab, str) + 1)) == NULL)
		return (NULL);
	ft_copy(tab, str, &joined);
	return (joined);
}
