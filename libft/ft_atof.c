/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:50 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/29 16:13:24 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	int		i;
	int		j;
	int		signe;
	float	nbr;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] && ft_isspace(str[i]) == 1)
		++i;
	if (str[i] == '-' && (++i) != -1)
		signe = -1;
	while (ft_isdigit(str[i]) == 1)
		nbr = (nbr * 10) + str[i++] - '0';
	if (str[i] == '.')
	{
		++i;
		j = 1;
		while (ft_isdigit(str[i]) == 1)
			nbr += (str[i++] - '0') / pow(10, j++);
	}
	return (nbr * signe);
}
