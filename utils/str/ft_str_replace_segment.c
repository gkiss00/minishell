/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace_segment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:33:05 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/minishell.h"

char		*ft_str_replace_segment(char *str, int start, int len, char *seg)
{
	str = ft_str_delete_segment(str, start, len);
	str = ft_str_add_segment(str, start, seg);
	return (str);
}
