/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:51:23 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_hub(t_data *data, char *cmd)
{
	char	*cmd_maj;
	int		flag;

	data->last_output = 0;
	flag = 1;
	if (ft_strcmp(cmd, "exit") == 0)
		ft_exit(data);
	else if (ft_strcmp(cmd, "export") == 0)
		ft_export(data);
	else if (ft_strcmp(cmd, "unset") == 0)
		ft_unset(data);
	else if (ft_strcmp(cmd, "cd") == 0)
		ft_cd(data);
	else
		flag = 0;
	cmd_maj = ft_tomaj(cmd);
	if (ft_strcmp(cmd_maj, "ECHO") == 0)
		ft_echo(data);
	else if (ft_strcmp(cmd_maj, "PWD") == 0)
		ft_pwd(data);
	else if (ft_strcmp(cmd_maj, "ENV") == 0)
		ft_env(data);
	else if (flag == 0)
		ft_exec(data);
	free(cmd_maj);
}
