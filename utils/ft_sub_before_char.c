/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_before_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:27:47 by gkiss            ###   ########.fr       */
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

char		*ft_sub_before_char(char *str, char c)
{
	int		end;
	char	*new;

	new = NULL;
	if (str == NULL)
		return (NULL);
	end = ft_find_first_match(str, c);
	if (end == -1)
		return (NULL);
	new = ft_substr(str, 0, end);
	return (new);
}
