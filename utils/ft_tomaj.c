#include "../header/minishell.h"

char    *ft_tomaj(char *str)
{
    int     i;
    char    *tmp;

    i = 0;
    if (str == NULL)
        return (NULL);
    if ((tmp = malloc(ft_strlen(str) + 1)) == NULL)
        return (NULL);
    while(str[i])
    {
        tmp[i] = ft_toupper(str[i]);
        ++i;
    }
    tmp[i] = '\0';
    return (tmp);
}