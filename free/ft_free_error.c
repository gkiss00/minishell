#include "../header/minishell.h"

int	            ft_free_error(t_data *data)
{
	ft_free_tab2(data->tabinput);
	data->tabinput = NULL;
	ft_free_tab2(data->tab_tmp);
	data->tab_tmp = NULL;
	ft_putstr_fd("minishell: malloc error: command cancel\n", 2);
	return (-1);
}