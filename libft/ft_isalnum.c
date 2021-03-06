/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:35:16 by cochapel          #+#    #+#             */
/*   Updated: 2019/10/24 15:22:38 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int yes_no;

	yes_no = 0;
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
	{
		yes_no = 1;
	}
	if (c <= '9' && c >= '0')
	{
		yes_no = 1;
	}
	return (yes_no);
}
