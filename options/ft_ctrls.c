/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corentin <corentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/10 21:40:51 by corentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_sigint(int n)
{
	signal(n, ft_sigint);
	if (pid_process != -1)
	{
		kill(pid_process, SIGINT);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		write(1, "\n-> minishell # ", 16);
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
	}
}