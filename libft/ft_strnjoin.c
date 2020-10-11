/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:45:24 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/17 19:02:54 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*s;
	int		s_len;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = -1;
	s_len = 0;
	s_len = ft_strlen(s1);
	s_len += ft_strlen(s2);
	if (!(s = malloc((s_len + 1) * sizeof(char))))
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i] && i < n)
	{
		s[j + i] = s2[i];
		i++;
	}
	s[j + i] = 0;
	return (s);
}
