/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:16:52 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/29 13:17:17 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_int(char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	if (c == '\0')
		return (i);
	while (--i >= 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}
