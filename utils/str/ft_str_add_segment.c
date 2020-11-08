#include "./../../header/minishell.h"

char    *ft_str_add_segment(char *str, int start, char *segment)
{
    char    *new;
    int     i;
    int     j;
    int     k;

    if (str == NULL || segment == NULL)
        return (NULL);
    if (str[0] == '\0' && start == 0 && ft_free_int(str))
        return (ft_strdup(segment));
    if ((int)ft_strlen(str) == start)
        return (ft_strjoin_free(str, segment, 1));
    if ((new = malloc(ft_strlen(str) + ft_strlen(segment) + 1)) == NULL)
        return (NULL);
    i = 0;
    j = 0;
    k = 0;
    while (str[i])
    {
        if (i == start)
            while (segment[k])
                new[j++] = segment[k++];
        new[j++] = str[i++];
    }
    new[j] = '\0';
    free(str);
    return (new);
}