/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tomaj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:28:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*ft_tomaj(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	if ((tmp = malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		tmp[i] = ft_toupper(str[i]);
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
