#include "./../../header/minishell.h"

char    *ft_str_replace_segment(char *str, int start, int len, char *segment)
{
    str = ft_str_delete_segment(str, start, len);
    str = ft_str_add_segment(str, start, segment);
    return (str);
}