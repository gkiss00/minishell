/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/10/11 11:33:23 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

extern pid_t	pid_process;
extern char		*command_name;

void	ft_sigint(int n)
{
	signal(n, ft_sigint);
	if (pid_process != -1)
	{
		kill(pid_process, SIGINT);
		ft_putchar_fd('\n', 2);
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
		ft_putstr_fd("[1]    604 quit		", 2);
		if (command_name != NULL)
			ft_putstr_fd(command_name, 2);
		ft_putchar_fd('\n', 2);
	}
	else
	{
		write(1, "\n-> minishell # ", 16);
		write(1, "\a", 1); // c'est sensé faire un beep la commande marche dans un petit programme
	}
}