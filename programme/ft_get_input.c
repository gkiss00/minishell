/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:00:23 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static char	**ft_split_input(char *in)
{
	return (ft_sp_split(in, ';'));
}

static void	ft_ctrl_d(t_data *data)
{
	int tmp;

	tmp = data->last_output;
	ft_putstr_fd("exit\n", 1);
	ft_free_data(data);
	exit(tmp);
}

static int	ft_pipe_ok(t_data *data)
{
	data->i1 = 0;
	data->i2 = 0;
	if (data->gnl_line == NULL)
		return (-1);
	while (data->gnl_line[data->i1] != '\0')
	{
		if (data->gnl_line[data->i1] == '|')
		{
			data->i2 = 1;
			++data->i1;
		}
		if (data->gnl_line[data->i1] == '\0')
			break ;
		if (data->gnl_line[data->i1] != '|' && data->gnl_line[data->i1] != ' ')
			data->i2 = 0;
		++data->i1;
	}
	data->i1 = 0;
	if (data->i2 == 0)
		return (1);
	data->i2 = 0;
	return (-1);
}

static int	ft_quote_ok(t_data *data)
{
	data->c1 = 0;
	data->c2 = 0;
	if (data->gnl_line == NULL)
		return (-1);
	while (data->gnl_line[data->c1] != 0)
	{
		if (data->c2 == 0 && data->gnl_line[data->c1] == '\'')
			data->c2 = 1;
		else if (data->c2 == 0 && data->gnl_line[data->c1] == '"')
			data->c2 = 2;
		else if (data->c2 == 1 && data->gnl_line[data->c1] == '\'')
			data->c2 = 0;
		else if (data->c2 == 2 && data->gnl_line[data->c1] == '"')
			data->c2 = 0;
		++data->c1;
	}
	if (data->c2 == 0)
		return (1);
	if (data->c2 == 2)
		ft_putchar_fd('d', 1);
	ft_putstr_fd("quote> ", 1);
	return (-1);
}

int			ft_get_input(t_data *data)
{
	while (ft_quote_ok(data) == -1 || ft_pipe_ok(data) == -1)
	{
		if ((data->gnl_ret = get_next_line(1, &data->gnl_tmp)) == -1)
			return (ft_error(data, NULL, MALLOC));
		if (data->gnl_ret == 0)
			ft_ctrl_d(data);
		if ((data->gnl_line =
		ft_strjoin_free(data->gnl_line, data->gnl_tmp, 2)) == NULL)
			return (ft_error(data, NULL, MALLOC));
	}
	if ((data->tabinput = ft_split_input(data->gnl_line)) == NULL)
		return (ft_error(data, NULL, MALLOC));
	free(data->gnl_line);
	data->gnl_line = NULL;
	data->gnl_tmp = NULL;
	return (0);
}
