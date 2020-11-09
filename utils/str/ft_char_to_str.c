#include "./../../header/minishell.h"

char    *ft_char_to_str(char c)
{
    char    *str;
    
    if ((str = malloc(2)) == NULL)
        return (NULL);
    str[0] = c;
    str[1] = 0;
    return (str);
}