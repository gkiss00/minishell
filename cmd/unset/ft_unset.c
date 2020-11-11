#include "../../header/minishell.h"

static int  ft_is_good_arg(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
        if (ft_isalnum(str[i]) != 1 && str[i] != '_')
            return (0);
		++i;
	}
	return (1);
}

static int  ft_strchr_unset(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (i);
}

static void ft_unset_var(t_data *data, char *name)
{
    int     i;
    char    *name_env;

    if (data->env == NULL)
        return ;
    i = 0;
    while (data->env[i] != NULL)
    {
        if ((name_env = ft_strndup(data->env[i], ft_strchr_unset(data->env[i], '='))) != NULL)
        {
            if (ft_strcmp(name_env, name) == 0)
            {
                data->env = ft_remove_from_tab(data->env, i);
                free(name_env);
                return ;
            }
            free(name_env);
        }
        ++i;
    }
}

void        ft_unset_arg(t_data *data, char *arg)
{
    if (ft_is_good_arg(arg) == 1)
    {
        ft_unset_var(data, arg);
    }
    else
    {
        ft_error(arg, UNSET);
    }
}

void        ft_unset(t_data *data)
{
    int i;

    if (data->cmd_tab[data->a]->arg == NULL)
        return ;
    i = 0;
    while (data->cmd_tab[data->a]->arg[i] != NULL)
    {
        ft_unset_arg(data, data->cmd_tab[data->a]->arg[i]);
        ++i;
    }
    data->last_output = 0;
}