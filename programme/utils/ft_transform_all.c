/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:03:06 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/minishell.h"

static int	transform_cmd(t_cmd *cmd)
{
	char	**tab;
	char	*tmp;

	tmp = NULL;
	tab = NULL;
	while (cmd)
	{
		tab = ft_copy_tab_transformed(cmd->arg);
		tmp = ft_transform(cmd->cmd);
		ft_free_tab1(cmd->cmd);
		ft_free_tab2(cmd->arg);
		cmd->cmd = tmp;
		cmd->arg = tab;
		cmd = cmd->next;
	}
	return (0);
}

void		ft_transform_all(t_data *data)
{
	int		i;

	i = 0;
	while (data->cmd_tab && data->cmd_tab[i])
	{
		transform_cmd(data->cmd_tab[i]);
		++i;
	}
}
