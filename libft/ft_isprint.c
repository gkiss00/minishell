/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:44:22 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/24 15:35:44 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int yes_no;

	yes_no = 0;
	if (c >= 32 && c <= 126)
	{
		yes_no = 1;
	}
	return (yes_no);
}