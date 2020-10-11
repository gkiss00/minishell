/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:04:09 by cochapel          #+#    #+#             */
/*   Updated: 2020/03/01 10:24:05 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_rest(char *s1, char *s2, int n)
{
	if (n == 1)
		free(s1);
	if (n == 2)
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strjoin_free(char *s1, char *s2, int n)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if ((str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	while (s2 != NULL && s2[k] != '\0')
	{
		str[i + k] = s2[k];
		++k;
	}
	str[i + k] = '\0';
	free_rest(s1, s2, n);
	return (str);
}
