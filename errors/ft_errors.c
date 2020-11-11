#include "../header/minishell.h"

int			ft_error(char *str, int i)
{
	ft_putstr_fd("minishell: ", 2);
	if (i == MALLOC)
		ft_putstr_fd("malloc error: command cancel", 2);
	if (i == NOT_FOUND)
	{
		ft_putstr_fd_int("command not found: ", 2);
		ft_putstr_fd(str, 2);
	}
	if (i == PARSE)
		ft_putstr_fd("parse error near `\\n'", 2);
	if (i == NO_FILE_OR_DIR)
	{
		ft_putstr_fd_int("no such file or directory ", 2);
		ft_putstr_fd_int(str, 2);
	}
	if (i == SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
	}
	if (i == PERMISSION_DENIED)
		ft_putstr_fd("Permission denied", 2);
	if (i == FORK)
		ft_putstr_fd("Fork failed", 2);
	ft_putstr_fd("'\n", 2);
	return (-1);
}
