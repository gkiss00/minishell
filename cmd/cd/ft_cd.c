/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 10:34:15 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/minishell.h"

static int	ft_save_env(t_data *data, char *new_path)
{
	int		ind_pwd;
	int		old_pwd;
	char	*t1;
	char	*t2;

	ind_pwd = ft_find_in_env(data->env, "PWD");
	old_pwd = ft_find_in_env(data->env, "OLDPWD");
	if (ind_pwd >= 0 && old_pwd >= 0)
	{
		t1 = ft_sub_after_char(data->env[ind_pwd], '=');
		t2 = ft_strjoin_free("OLDPWD=", t1, 3);
		data->env = ft_replace_from_tab(data->env, t2, old_pwd);
		free(t2);
		t2 = ft_strjoin_free("PWD=", new_path, 0);
		data->env = ft_replace_from_tab(data->env, t2, ind_pwd);
		free(t2);
	}
	return (0);
}

static int	ft_go(t_data *data)
{
	char *tmp;

	tmp = ft_get_path(data->path, data->cmd_tab[data->a]->arg[0]);
	if (tmp == NULL)
		return (ft_error(data, NULL, MALLOC));
	if (ft_does_dir_exist(tmp) == 0)
	{
		free(data->path);
		ft_save_env(data, tmp);
		data->path = tmp;
		return (0);
	}
	else
	{
		free(tmp);
		return (ft_error(data, NULL, NO_FILE_OR_DIR));
	}
}

static int	ft_go_home(t_data *data)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = ft_find_in_env(data->env, "HOME");
	if (index >= 0)
	{
		tmp = ft_sub_after_char(data->env[index], '=');
		if (tmp != NULL)
		{
			free(data->path);
			ft_save_env(data, tmp);
			data->path = tmp;
			return (0);
		}
		else
			return (ft_error(data, NULL, MALLOC));
	}
	else
		return (ft_error(data, NULL, NO_FILE_OR_DIR));
}

void		ft_cd(t_data *data)
{
	if (get_length(data->cmd_tab[data->a]->arg) == 0)
		ft_go_home(data);
	else
		ft_go(data);
}
