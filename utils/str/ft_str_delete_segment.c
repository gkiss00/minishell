#include "./../../header/minishell.h"

char    *ft_str_delete_segment(char *str, int start, int len)
{
    char    *new;
    int     i;
    int     j;

    if (ft_strlen(str) - len < 0)
        return (NULL);
    if ((new = malloc(ft_strlen(str) - len + 1)) == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (i < start || i >= start + len)
        {
            new[j] = str[i];
            ++j;
        }
        ++i;
    }
    new[j] = '\0';
    free(str);
    return (new);
}