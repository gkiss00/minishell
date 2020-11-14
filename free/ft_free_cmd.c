/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:08:52 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void		ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd != NULL)
	{
		next = cmd->next;
		ft_free_tab1(cmd->cmd);
		ft_free_tab2(cmd->arg);
		free(cmd);
		cmd = next;
	}
}
