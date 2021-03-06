/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:35:36 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void		ft_echo(t_data *data)
{
	int		i;

	i = 0;
	while (data->cmd_tab[data->a]->arg && data->cmd_tab[data->a]->arg[i])
	{
		ft_putstr_fd(data->cmd_tab[data->a]->arg[i], 1);
		if (data->cmd_tab[data->a]->arg[i + 1])
			ft_putstr_fd(" ", 1);
		++i;
	}
	if (data->cmd_tab[data->a]->opt == 0)
		ft_putstr_fd("\n", 1);
}
