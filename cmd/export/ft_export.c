#include "../../header/minishell.h"

static int  ft_is_good_arg(const char *str)
{
	int	i;
    int flag;

    flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
        if (flag == 0)
        {
            if (str[i] == '=')
                flag = 1;
            else if (ft_isalnum(str[i]) != 1 && str[i] != '_')
                return (0);
        }
		++i;
	}
	return (1);
}

static char *ft_add_quotes(char *str)
{
    char    *with_quotes;
    int     i;
    int     j;
    int     flag;

    if (ft_strchr(str, '=') == 0)
        return (ft_strdup(str));
    if ((with_quotes = malloc(ft_strlen(str) + 3)) == NULL)
        return (NULL);
    i = 0;
    j = 0;
    flag = 0;
    while (str[i] != '\0')
    {
        with_quotes[j] = str[i];
        ++j;
        if (flag == 0 && str[i] == '=')
        {
            with_quotes[j] = '"';
            ++j;
        }
        ++i;
    }
    with_quotes[j] = '"';
    with_quotes[j + 1] = '\0';
    return (with_quotes);
}

void        ft_print_env_export(char **env)
{
    int     i;
    char    *with_quotes;

    if (env == NULL)
        return ;
    i = 0;
    while (env[i] != NULL)
    {
        ft_putstr_fd("declare -x ", 1);
        if ((with_quotes = ft_add_quotes(env[i])) != NULL)
        {
            ft_putstr_fd(with_quotes, 1);
            free(with_quotes);
        }
        ft_putstr_fd("\n", 1);
        ++i;
    }
}

void        ft_export(t_data *data)
{
    int i;

    if (data->cmd_tab[data->a]->arg[0] == NULL)
    {
        ft_print_env_export(data->env);
    }
    i = 0;
    while (data->cmd_tab[data->a]->arg[i] != NULL)
    {
        if (ft_is_good_arg(data->cmd_tab[data->a]->arg[i]) == 1)
        {
            ft_unset_arg(data, data->cmd_tab[data->a]->arg[i]);
            ft_add_to_tab(data->env, data->cmd_tab[data->a]->arg[i]);
        }
        else
        {
            ft_putstr_fd("bash: export: '", 1);
            ft_putstr_fd(data->cmd_tab[data->a]->arg[i], 1);
            ft_putstr_fd("': not a valid identifier\n", 1);
        }
        ++i;
    }
}