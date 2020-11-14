/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options_echo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:01:12 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int      ft_is_n(char *str)
{
	int     i;

	i = 0;
	while (str && str[i])
	{
		if (i == 0 && str[i] != '-')
			return (1);
		if (i != 0 && str[i] != 'n')
			return (1);
		++i;
	}
	return (0);
}

static void     ft_check_for_n(t_cmd *cmd)
{
	int     i;

	i = 0;
	while (cmd->arg && cmd->arg[i])
	{
		if (ft_is_n(cmd->arg[i]) != 0)
			return ;
		if (ft_is_n(cmd->arg[i]) == 0)
		{
			cmd->opt = 1;
			cmd->arg = ft_remove_front_tab(cmd->arg);
		}
	}
}

static void     ft_is_echo(t_cmd *cmd)
{
	char    *tmp1;
	char    *tmp2;

	tmp1 = ft_transform(cmd->cmd);
	tmp2 = ft_tomaj(tmp1);
	if (ft_strcmp(tmp2, "ECHO") == 0)
	{
		ft_check_for_n(cmd);
	}
	ft_free_tab1(tmp1);
	ft_free_tab1(tmp2);
}

void            ft_check_options_echo(t_data *data)
{
    int     i;

	i = 0;
	while (data->cmd_tab && data->cmd_tab[i])
	{
		if (data->cmd_tab[i]->type == 0 || data->cmd_tab[i]->type == 1)
		{
			ft_is_echo(data->cmd_tab[i]);
		}
		++i;
	}
}
