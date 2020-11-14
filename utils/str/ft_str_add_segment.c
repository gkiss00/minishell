/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:36:32 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/minishell.h"

char		*ft_str_add_segment(char *str, int start, char *segment)
{
	char	*new;
	int		c[3];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	if (str == NULL || segment == NULL)
		return (NULL);
	if (str[0] == '\0' && start == 0 && ft_free_int(str))
		return (ft_strdup(segment));
	if ((int)ft_strlen(str) == start)
		return (ft_strjoin_free(str, segment, 1));
	if ((new = malloc(ft_strlen(str) + ft_strlen(segment) + 1)) == NULL)
		return (NULL);
	while (str[c[0]])
	{
		if (c[0] == start)
			while (segment[c[2]])
				new[c[1]++] = segment[c[2]++];
		new[c[1]++] = str[c[0]++];
	}
	new[c[1]] = '\0';
	free(str);
	return (new);
}
