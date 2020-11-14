/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corentin <corentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 08:25:12 by corentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_remove_print(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putstr_fd("\b", 1);
		++i;
	}
	i = 0;
	while (i < n)
	{
		ft_putstr_fd(" ", 1);
		++i;
	}
	i = 0;
	while (i < n)
	{
		ft_putstr_fd("\b", 1);
		++i;
	}
}

void	ft_sigint(int n)
{
	signal(n, ft_sigint);
	if (pid_process != -1)
	{
		kill(pid_process, SIGINT);
		ft_putchar_fd('\n', 1);
		output_ctrls = 130;
	}
	else
	{
		ft_remove_print(2);
		write(1, "\n-> minishell # ", 16);
		output_ctrls = 1;
		is_ctrl_c = 1;
	}
}

void	ft_sigquit(int n)
{
	signal(n, ft_sigquit);
	if (pid_process != -1)
	{
		kill(pid_process, SIGQUIT);
		ft_putstr_fd("Quit: 3", 1);
		ft_putchar_fd('\n', 1);
		output_ctrls = 131;
	}
	else
	{
		ft_remove_print(2);
	}
}