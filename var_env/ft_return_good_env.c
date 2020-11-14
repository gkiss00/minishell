/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_good_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:51:19 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/minishell.h"

char		*ft_return_good_env(char **env, int i)
{
	char	*new;

	if (env == NULL || i < 0 || i >= get_length(env))
		return (NULL);
	new = ft_sub_after_char(env[i], '=');
	return (new);
}

char		*ft_replace_free(char *tmp, int i, char *str)
{
	str = ft_str_replace_segment(str, i, 2, tmp);
	free(tmp);
	return (str);
}
