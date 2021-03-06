/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:45:08 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	ft_is_arg_valid(t_data *data, char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0' && (arg[i] == '-' || arg[i] == '+'))
		++i;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) != 1)
		{
			ft_error(data, arg, EXIT);
			return (0);
		}
		++i;
	}
	return (1);
}

static int	ft_nbr_args(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		++i;
	}
	return (i);
}

void		ft_exit(t_data *data)
{
	int ret;

	ft_putstr_fd("exit\n", 1);
	if (data->cmd_tab[data->a]->arg == NULL
	|| data->cmd_tab[data->a]->arg[0] == NULL)
		ret = 0;
	else
	{
		if (ft_is_arg_valid(data, data->cmd_tab[data->a]->arg[0]) == 0)
			ret = 255;
		else
		{
			if (ft_nbr_args(data->cmd_tab[data->a]->arg) > 1)
			{
				ft_putstr_fd("minishell: exit: too many arguments\n", 2);
				data->last_output = 1;
				return ;
			}
			ret = ft_atoi(data->cmd_tab[data->a]->arg[0]);
		}
	}
	ft_free_data(data);
	exit(ret);
}
