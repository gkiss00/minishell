#include "../header/minishell.h"

void			ft_write_export_error(t_data *data, int i)
{
    ft_error(data->cmd_tab[data->a]->arg[i], EXPORT);
    data->last_output = 1;
}

static void		ft_error2(char *str, int i)
{
	if (i == FORK)
		ft_putstr_fd("Fork failed", 2);
	else if (i == UNSET)
	{
		ft_putstr_fd("unset: '", 2);
        ft_putstr_fd(str, 2);
        ft_putstr_fd("': not a valid identifier", 2);
	}
	else if (i == EXPORT)
	{
		ft_putstr_fd("export: '", 2);
    	ft_putstr_fd(str, 2);
    	ft_putstr_fd("': not a valid identifier", 2);
	}
	else if (i == EXEC)
	{
        ft_putstr_fd(str, 2);
        ft_putstr_fd(": command not found", 2);
	}
	else if (i == EXIT)
	{
		ft_putstr_fd("exit: ", 2);
        ft_putstr_fd(str, 2);
        ft_putstr_fd(": numeric argument required", 2);
	}
}

int			ft_error(char *str, int i)
{
	ft_putstr_fd("minishell: ", 2);
	if (i == MALLOC)
		ft_putstr_fd("malloc error: command cancel", 2);
	else if (i == NOT_FOUND)
	{
		ft_putstr_fd_int("command not found: ", 2);
		ft_putstr_fd(str, 2);
	}
	else if (i == PARSE)
		ft_putstr_fd("parse error near `\\n'", 2);
	else if (i == NO_FILE_OR_DIR)
	{
		ft_putstr_fd_int("no such file or directory ", 2);
		ft_putstr_fd_int(str, 2);
	}
	else if (i == SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
	}
	else if (i == PERMISSION_DENIED)
		ft_putstr_fd("Permission denied", 2);
	else
		ft_error2(str, i);
	ft_putstr_fd("'\n", 2);
	return (-1);
}
