/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:04:03 by cochapel          #+#    #+#             */
/*   Updated: 2020/01/16 09:42:15 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd_int(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
		return (1);
	}
	return (0);
}
