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

    if (str == NULL)
        return (NULL);
    if (ft_strchr_int(str, '=') == -1)
        return (ft_strdup(str));
    if ((with_quotes = malloc(ft_strlen(str) + 3)) == NULL)
        return (NULL);
    i = -1;
    j = -1;
    flag = 0;
    while (str[++i] != '\0')
    {
        with_quotes[++j] = str[i];
        if (flag == 0 && str[i] == '=')
        {
            with_quotes[++j] = '"';
            flag = 1;
        }
    }
    with_quotes[j] = '"';
    with_quotes[j + 1] = '\0';
    return (with_quotes);
}

static int  ft_print_env_export(char **env)
{
    int     i;
    char    *with_quotes;

    if (env == NULL)
        return (0);
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
    return (0);
}

static int  ft_exists(char **env, char *name)
{
    int     i;
    char    *tmp;

    if (env == NULL)
        return (-1);
    i = 0;
    while (env[i] != NULL)
    {
        if (ft_strchr_int(name, '=') == -1)
            tmp = ft_strdup(env[i]);
        else
            tmp = ft_sub_before_char(env[i], '=');
        if (ft_strcmp(tmp, name) == 0)
        {
            free(tmp);
            return (1);
        }
        free(tmp);
        ++i;
    }
    return (0);
}

void        ft_export(t_data *data)
{
    int     i;
    char    *tmp;

    if (data->cmd_tab[data->a]->arg == NULL && ft_print_env_export(data->env) == 0)
        return ;
    i = -1;
    while (data->cmd_tab[data->a]->arg[++i] != NULL)
    {
        if (ft_is_good_arg(data->cmd_tab[data->a]->arg[i]) == 1)
        {
            if (ft_strchr_int(data->cmd_tab[data->a]->arg[i], '=') != -1)
            {
                if ((tmp = ft_sub_before_char(data->cmd_tab[data->a]->arg[i], '=')) != NULL)
                {
                    ft_unset_arg(data, tmp);
                    free(tmp);
                    data->env = ft_add_to_tab(data->env, data->cmd_tab[data->a]->arg[i]);
                }
            }
            else if (ft_exists(data->env, data->cmd_tab[data->a]->arg[i]) == 0)
                data->env = ft_add_to_tab(data->env, data->cmd_tab[data->a]->arg[i]);
        }
        else
            ft_write_export_error(data, i);
    }
}