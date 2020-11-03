#include "./../header/minishell.h"

char    *ft_return_good_env(char **env, int i)
{
    char    *new;

    if (env == NULL || i < 0 || i >= get_length(env))
        return (NULL);
    new = ft_sub_after_char(env[i], '=');
    return (new);
}