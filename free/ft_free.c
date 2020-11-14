/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:39:02 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void		ft_free_cmd2(t_cmd **cmd)
{
	int		i;

	i = 0;
	if (cmd)
	{
		while (cmd[i] != NULL)
		{
			ft_free_cmd(cmd[i]);
			++i;
		}
		free(cmd);
	}
}

int			ft_free_tab2_int(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (1);
	while (tab[i] != NULL)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (1);
}

void		ft_free_tab2(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

void		ft_free_tab1(char *str)
{
	if (str)
		free(str);
}

int			ft_free_int(char *str)
{
	free(str);
	return (1);
}
