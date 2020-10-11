/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:28:56 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/17 19:05:29 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_int(int n, int fd)
{
	int		i;
	char	str[50];

	i = 11;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		i = 0;
		if (n < 0)
		{
			str[i++] = '-';
			n = n * -1;
		}
		while (n >= 10)
		{
			str[i++] = (n % 10) + '0';
			n = n / 10;
		}
		str[i++] = (n % 10) + '0';
		str[i] = 0;
		ft_putstr_fd(str, fd);
	}
	return (i);
}
