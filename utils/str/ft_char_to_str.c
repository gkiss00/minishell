/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:31:49 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/minishell.h"

char		*ft_char_to_str(char c)
{
	char		*str;

	if ((str = malloc(2)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}
