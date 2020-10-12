#include "../header/minishell.h"

int         ft_is_quote(char *str, int i, int *c)
{
    int     tmp;

    tmp = *c;
    if (*c == 0 && str[i] == '\'')
        *c = 1;
    else if (*c == 0 && str[i] == '"')
        *c = 2;
    else if (*c == 1 && str[i] == '\'')
        *c = 0;
    else if (*c == 2 && str[i] == '"')
        *c = 0;
    if(tmp == *c)
        return(-1);
    return(1);
}

void         ft_quote(char *str, int *c, int i, int *s)
{
    int     tmp;

    tmp = *c;
    if (*c == 0 && str[i] == '\'')
        *c = 1;
    else if (*c == 0 && str[i] == '"')
        *c = 2;
    else if (*c == 1 && str[i] == '\'')
        *c = 0;
    else if (*c == 2 && str[i] == '"')
        *c = 0;
    if(tmp == *c)
        ++*s;    
}

int         ft_size(char *str)
{
    int     i;
    int     c;
    int     size;

    i = 0;
    c = 0;
    size = 0;
    while(str[i] != '\0')
    {
        ft_quote(str, &c, i, &size);
        ++i;
    }
    return(size);
}

char        *ft_copy_transformed(char *str)
{
    int     i;
    int     j;
    int     c;
    char    *tmp;

    i = 0;
    j = 0;
    c = 0;
    if ((tmp = malloc(ft_size(str) + 1)) == NULL)
        return (NULL);
    while(str[i] != '\0')
    {
        if(ft_is_quote(str, i, &c) == -1)
        {
            tmp[j] = str[i];
            ++j;
        }
        ++i;
    }
    tmp[j] = '\0';
    return (tmp);
}

char        *ft_transform(char *str)
{
    char *tmp;

    tmp = ft_copy_transformed(str);
    return (tmp);
}