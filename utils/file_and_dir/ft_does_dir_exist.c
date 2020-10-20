#include "../../header/minishell.h"

int     ft_does_dir_exist(char *path)
{
    DIR     *dir;

    dir = opendir(path);
    if (dir == NULL)
        return (-1);
    closedir(dir);
    return (0);
}