#include "../header/minishell.h"

static int	ft_error_next(char *str, int i)
{
	if (i == 3)
		ft_putstr_fd("minishell: parse error near `\\n'\n", 2);
	if (i == 4 && ft_putstr_fd_int("minishell: no such file or directory: ", 2)
			!= -1 && ft_putstr_fd_int(str, 2) != -1)
		ft_putchar_fd('\n', 2);
	if (i == 5)
		ft_putstr_fd("pwd: too many arguments\n", 2);
	return (-1);
}

int			ft_error(char *str, int i)
{
	if (i == 1)
		ft_putstr_fd("minishell: malloc error: command cancel\n", 2);
	if (i == 2 && ft_putstr_fd_int("minishell: command not found: ", 2) != -1)
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	return (ft_error_next(str, i));
}
