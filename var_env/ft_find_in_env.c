#include "./../header/minishell.h"

static int  ft_does_match(char *env, char *str)
{
    char    *tmp;
    int     ret;

    ret = 1;
    tmp = ft_sub_before_char(env, '=');
    if(ft_strcmp(tmp, str) == 0)
        ret = 0;
    free(tmp);
    return (ret);
}

int         ft_find_in_env(char **env, char *str)
{
    int     i;

    i = 0;
    if(env == NULL)
        return (-1);
    while(env[i])
    {
        if(ft_does_match(env[i], str) == 0)
            return (i);
        ++i;
    }
    return (-1);
}