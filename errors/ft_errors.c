#include "../header/minishell.h"

int			ft_error(char *str, int i)
{
	if (i == MALLOC)
		ft_putstr_fd("minishell: malloc error: command cancel\n", 2);
	if (i == NOT_FOUND)
	{
		ft_putstr_fd_int("minishell: command not found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	if (i == PARSE)
		ft_putstr_fd("minishell: parse error near `\\n'\n", 2);
	if (i == NO_FILE_OR_DIR)
	{
		ft_putstr_fd_int("minishell: no such file or directory ", 2);
		ft_putstr_fd_int(str, 2);
		ft_putchar_fd('\n', 2);
	}
	if (i == SYNTAX)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("'\n", 2);
	}
	if (i == PERMISSION_DENIED)
	{
		ft_putstr_fd("minishell: Permission denied\n", 2);
	}
	if (i == FORK)
	{
		ft_putstr_fd("minishell: Fork failed\n", 2);
	}
	return (-1);
}
