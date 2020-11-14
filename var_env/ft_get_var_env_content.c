/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_env_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:49:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/minishell.h"

char		*ft_get_var_env_content(char **env, char *var_env_name)
{
	char	*var_env_content;
	int		index;

	index = ft_find_in_env(env, var_env_name);
	if (index == -1)
		return (NULL);
	var_env_content = ft_return_good_env(env, index);
	return (var_env_content);
}
