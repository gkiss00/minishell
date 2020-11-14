/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:09:09 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void		ft_free_data(t_data *data)
{
	int		i;

	if (!data)
		return ;
	ft_free_tab1(data->gnl_line);
	data->gnl_line = NULL;
	ft_free_tab1(data->gnl_tmp);
	data->gnl_tmp = NULL;
	ft_free_tab2(data->tabinput);
	data->tabinput = NULL;
	ft_free_tab2(data->env);
	data->env = NULL;
	ft_free_tab1(data->path);
	data->path = NULL;
	ft_free_tab1(data->readed);
	data->readed = NULL;
	ft_free_cmd(data->cmd);
	data->cmd = NULL;
	if (data->cmd_tab != NULL && (i = -1) == -1)
		while (data->cmd_tab[++i] != NULL)
			ft_free_cmd(data->cmd_tab[i]);
	free(data->cmd_tab);
	data->cmd_tab = NULL;
	free(data);
}
