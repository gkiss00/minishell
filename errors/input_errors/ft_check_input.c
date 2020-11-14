/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:06:27 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	is_pipe(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_strcmp(str, "|") == 0)
		return (0);
	return (1);
}

static int	is_redir(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_strcmp(str, "<") == 0)
		return (0);
	if (ft_strcmp(str, "|") == 0)
		return (0);
	if (ft_strcmp(str, ">") == 0)
		return (0);
	if (ft_strcmp(str, ">>") == 0)
		return (0);
	return (1);
}

static int	check_for_errors(t_data *data, char **tmp)
{
	int		i;

	i = 0;
	if (tmp == NULL)
		return (ft_error(data, NULL, MALLOC));
	while (tmp && tmp[i])
	{
		if (i == 0 && ft_strcmp(tmp[0], "|") == 0)
			return (ft_error(data, "|", SYNTAX));
		if (is_redir(tmp[i]) == 0 && is_pipe(tmp[i + 1]) == 0)
			return (ft_error(data, "|", SYNTAX));
		if (is_redir(tmp[i]) == 0
		&& (is_redir(tmp[i + 1]) == 0 || tmp[i + 1] == NULL))
			return (ft_error(data, "newline", SYNTAX));
		++i;
	}
	return (0);
}

int			ft_check_input(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->tabinput && data->tabinput[i])
	{
		tmp = ft_sp_split(data->tabinput[i], ' ');
		if (check_for_errors(data, tmp) == -1)
		{
			ft_free_tab2(tmp);
			return (-1);
		}
		ft_free_tab2(tmp);
		++i;
	}
	return (0);
}
