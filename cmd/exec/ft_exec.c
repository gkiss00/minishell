/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corentin <corentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/15 12:35:19 by corentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static char	*ft_find_path_from_env(t_data *data, char *str)
{
	char	*path;
	char	**paths;
	char	backslash[2];
	int		i;

	if ((paths = ft_get_path_content(data->env)) == NULL)
		return (NULL);
	backslash[0] = '/';
	backslash[1] = '\0';
	i = 0;
	while (paths[i] != NULL)
	{
		if ((path = ft_strjoin(paths[i], backslash)) == NULL
		&& ft_free_tab2_int(paths))
			return (NULL);
		if ((path = ft_strjoin_free(path, str, 1)) == NULL
		&& ft_free_tab2_int(paths))
			return (NULL);
		if (ft_is_path_valid(path) == 1 && ft_free_tab2_int(paths))
			return (path);
		free(path);
		++i;
	}
	ft_free_tab2(paths);
	return (NULL);
}

static char	*ft_find_path(t_data *data, char *str)
{
	char	*path;
	char	*tmp;
	char	*tmp2;

	if (str[0] == '/')
	{
		if ((path = ft_strdup(str)) == NULL)
			return (NULL);
	}
	else if ((path = ft_find_path_from_env(data, str)) == NULL)
	{
		if ((tmp = ft_get_var_env_content(data->env, "PWD")) == NULL)
			return (NULL);
		if ((tmp2 = ft_strjoin(tmp, "/")) == NULL && ft_free_int(tmp))
			return (NULL);
		if ((path = ft_strjoin(tmp2, str)) == NULL
		&& ft_free_int(tmp) && ft_free_int(tmp2))
			return (NULL);
		free(tmp);
		free(tmp2);
	}
	if (ft_is_path_valid(path) == 1)
		return (path);
	free(path);
	return (NULL);
}

static char	**ft_get_execve_args(char *cmd, char **args)
{
	char	*cmd_tab[2];
	char	**tmp;
	char	**ret;

	if ((cmd_tab[0] = ft_strdup(cmd)) == NULL)
		return (NULL);
	cmd_tab[1] = NULL;
	if ((tmp = ft_copy_tab(args)) != NULL)
	{
		if ((ret = ft_join_two_tabs(cmd_tab, tmp)) == NULL
		&& ft_free_int(cmd_tab[0]))
			return (NULL);
		ft_free_tab2(tmp);
	}
	else if ((ret = ft_copy_tab(cmd_tab)) == NULL && ft_free_int(cmd_tab[0]))
		return (NULL);
	free(cmd_tab[0]);
	return (ret);
}

static void	ft_close_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

int			ft_exec(t_data *data)
{
	char	*path;
	int		fd[2];

	if ((path = ft_find_path(data, data->cmd_tab[data->a]->cmd)) == NULL)
		return (ft_error(data, data->cmd_tab[data->a]->cmd, EXEC));
	pipe(fd);
	if ((g_pid_process = fork()) == 0)
	{
		if (data->readed != NULL)
			dup2(fd[0], 0);
		ft_close_pipe(fd);
		chdir(ft_get_var_env_content(data->env, "PWD"));
		execve(path, ft_get_execve_args(data->cmd_tab[data->a]->cmd,
		data->cmd_tab[data->a]->arg), ft_copy_tab(data->env));
		exit(1);
	}
	if (data->readed != NULL)
		ft_putstr_fd(data->readed, fd[1]);
	ft_close_pipe(fd);
	wait(&g_pid_process);
	data->last_output = WEXITSTATUS(g_pid_process);
	g_pid_process = -1;
	free(path);
	return (0);
}
