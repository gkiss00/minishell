#include "./../header/minishell.h"

char    *ft_return_good_env(char **env, int i)
{
    char    *new;

    if (env == NULL || i < 0 || i >= get_length(env))
        return (NULL);
    new = ft_sub_after_char(env[i], '=');
    return (new);
}


char    *ft_replace_free(char *tmp, int i, char *str)
{
    str = ft_str_replace_segment(str, i, 2, tmp);
    free(tmp);
    return (str);
}