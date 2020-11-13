#include "./../header/minishell.h"

static int  ft_is_in_simple_quote(char *str, int index)
{
    int i;
    int in_double_quote;
    int in_simple_quote;
    int flag;

    if (str == NULL)
        return (-1);
    i = -1;
    in_double_quote = 0;
    in_simple_quote = 0;
    while (str[++i])
    {
        flag = 0;
        if (str[i] == '\'' && in_double_quote == 0 && in_simple_quote == 0)
        {
            in_simple_quote = 1;
            flag = 1;
        }
        if (str[i] == '"' && in_simple_quote == 0)
            in_double_quote = in_double_quote == 0 ? 1 : 0;
        if (i == index)
            return (in_simple_quote == 0 ? -1 : 0);
        if (str[i] == '\'' && in_double_quote == 0 && in_simple_quote == 1 && flag != 1)
            in_simple_quote = 0;
    }
    return (-1);
}

static int  ft_strchr_env(const char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
        if (ft_isalnum(str[i]) != 1 && str[i] != '_')
            return (i);
		++i;
	}
	return (i);
}

static int  ft_is_var_env(char *str, char **var_env_name)
{
    if (str == NULL)
        return (-1);
    if (str[0] == '$')
    {
        if (str[1] == '$')
            return (1);
        if (str[1] == '?')
            return (2);
        if (ft_isalnum(str[1]) != 1 && str[1] != '_')
            return (-1);
        var_env_name[0] = ft_strndup(&str[1], ft_strchr_env(&str[1]));
        return (0);
    }
    return (-1);
}

static char *ft_replace_env_char(t_data *data, char *str, char **env, int i)
{
    char    *var_env_name;
    char    *var_env_content;
    char    *tmp;
    int     ret;

    ret = ft_is_var_env(&str[i], &var_env_name);
    if (ret == 0)
    {
        var_env_content = ft_get_var_env_content(env, var_env_name);
        if (var_env_content != NULL)
        {
            str = ft_str_replace_segment(str, i, ft_strlen(var_env_name) + 1, var_env_content);
            free(var_env_content);
        }
        else
            str = ft_str_delete_segment(str, i, ft_strlen(var_env_name) + 1);
        free(var_env_name);
    }
    else if (ret == 1)
        str = ft_replace_free(ft_itoa(getpid()), i, str);
    else if (ret == 2)
        str = ft_replace_free(ft_itoa(data->last_output), i, str);
    return (str);
}

char    *ft_replace_env(t_data *data, char *str, char **env)
{
    int     i;

    i = -1;
    while (str != NULL && str[++i])
    {
        if (ft_is_in_simple_quote(str, i) != 0)
        {
            str = ft_replace_env_char(data, str, env, i);
        }
    }
    return (str);
}