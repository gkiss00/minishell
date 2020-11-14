/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_after_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:27:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/minishell.h"

static int	ft_find_first_match(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char		*ft_sub_after_char(char *str, char c)
{
	int		start;
	int		length;
	char	*new;

	new = NULL;
	if (str == NULL)
		return (NULL);
	start = ft_find_first_match(str, c);
	if (start == -1)
		return (NULL);
	length = ft_strlen(str);
	new = ft_substr(str, start + 1, length);
	return (new);
}
