/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:50:15 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/13 10:08:40 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, int n)
{
	int		i;
	int		len;
	char	*s2;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1) > n ? n : ft_strlen(s1);
	if (!(s2 = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
