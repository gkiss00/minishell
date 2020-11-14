/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:07:00 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/minishell.h"

static int	ft_read_fd(t_data *data, t_cmd *cmd)
{
	int		fd;
	char	*path;

	path = ft_get_path(data->path, cmd->cmd);
	fd = open(path, O_WRONLY | O_APPEND);
	free(path);
	return (fd);
}

static void	ft_redirect(t_data *data, t_cmd *cmd)
{
	int		fd;
	char	*path;

	path = ft_get_path(data->path, cmd->cmd);
	if (cmd->type == 4)
		fd = ft_read_fd(data, cmd);
	else
	{
		fd = open(path, O_WRONLY | O_TRUNC);
		free(path);
	}
	if (data->fd == -1)
		data->fd = dup(1);
	dup2(fd, 1);
	close(fd);
}

void		ft_do_redirections(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd_tab[data->a];
	while (cmd)
	{
		if (cmd->type == 3 || cmd->type == 4)
			ft_redirect(data, cmd);
		cmd = cmd->next;
	}
}
