/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:44:00 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int		ft_is_path_valid(char *path)
{
	struct stat		buffer;

	if (stat(path, &buffer) == 0)
		return (1);
	return (0);
}

char	**ft_get_path_content(char **env)
{
	char	*path_content;
	char	**paths;

	if ((path_content = ft_get_var_env_content(env, "PATH")) == NULL)
		return (NULL);
	if ((paths = ft_split(path_content, ':')) == NULL)
	{
		free(path_content);
		return (NULL);
	}
	free(path_content);
	return (paths);
}
