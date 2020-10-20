#include "../../header/minishell.h"

int     ft_does_file_exist(char *path)
{
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (-1);
    close(fd);
    return (0);
}