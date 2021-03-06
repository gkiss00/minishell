/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:50:57 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/minishell.h"

static void	ft_check_var_env_arg(t_data *data, t_cmd *cmd, char **env)
{
	int		i;

	i = 0;
	cmd->cmd = ft_replace_env(data, cmd->cmd, env);
	while (cmd->arg && cmd->arg[i])
	{
		cmd->arg[i] = ft_replace_env(data, cmd->arg[i], env);
		++i;
	}
}

static void	ft_check_var_env_cmd(t_data *data, t_cmd *cmd, char **env)
{
	while (cmd)
	{
		ft_check_var_env_arg(data, cmd, env);
		cmd = cmd->next;
	}
}

void		ft_check_var_env(t_data *data)
{
	int		i;

	i = 0;
	while (data->cmd_tab && data->cmd_tab[i])
	{
		ft_check_var_env_cmd(data, data->cmd_tab[i], data->env);
		++i;
	}
}
