/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:14:56 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/17 19:03:59 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char const *s1, char const *s2, int n)
{
	char	*s;
	int		s_len;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strndup(s2, n));
	if (s2 == 0)
		return (ft_strndup(s1, n));
	i = -1;
	s_len = ft_strlen(s1);
	s_len += ft_strlen(s2);
	if (!(s = malloc((s_len + 1) * sizeof(char))))
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j] && j < n)
		s[i + j] = s2[j];
	s[j + i] = 0;
	free((void *)s1);
	return (s);
}
