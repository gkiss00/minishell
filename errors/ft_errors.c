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
	if (i == 3)
		ft_putstr_fd("minishell: parse error near `\\n'\n", 2);
	if (i == NO_FILE_OR_DIR)
	{
		ft_putstr_fd_int("minishell: no such file or directory: ", 2);
		ft_putstr_fd_int(str, 2);
		ft_putchar_fd('\n', 2);
	}
	if (i == REDIRECTION)
		ft_putstr_fd("syntax error near unexpected token `newline'", 2);
	return (-1);
}
