/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:40:10 by cochapel          #+#    #+#             */
/*   Updated: 2019/11/05 08:29:32 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	if (s == 0)
		return (0);
	lenght = 0;
	while (s[lenght])
	{
		lenght++;
	}
	return (lenght);
}
