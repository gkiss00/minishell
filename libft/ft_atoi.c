/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:45:18 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/29 16:12:12 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nbr;
	int					sign;

	if (str == 0)
		return (0);
	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	if (nbr > 9223372036854775807 && sign == 1)
		return (-1);
	if (nbr > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * nbr);
}
