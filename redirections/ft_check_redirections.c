#include "../header/minishell.h"

static char *get_file_path(char *current, char *file)
{
    char    *tmp;

    tmp = ft_strjoin(current, "/");
    tmp = ft_strjoin_free(tmp, file, 1);
    ft_free_tab1(file);
    return (tmp);
}

static int  file_exist(t_cmd *cmd, char *current)
{
    int     ret;
    char    *tmp;

    tmp = ft_transform(cmd->cmd);
    if (ft_strcmp(tmp, "") == 0)
    {
        ft_free_tab1(tmp);
        return (ft_error(NULL, NO_FILE_OR_DIR));
    }
    if ((tmp = get_file_path(current, tmp)) == NULL)
        return (ft_error(NULL, MALLOC));
    ret = ft_does_file_exist(tmp);
    ft_free_tab1(tmp);
    return (ret);
}

static int  check_file(t_cmd *cmd, char *current)
{
    int     fd;
    char    *tmp;

    tmp = ft_transform(cmd->cmd);
    if (ft_strcmp(tmp, "") == 0)
    {
        ft_free_tab1(tmp);
        puts("oui");
        return (ft_error(NULL, NO_FILE_OR_DIR));
    }
    if ((tmp = get_file_path(current, tmp)) == NULL)
        return (ft_error(NULL, MALLOC));
    fd = open(tmp, O_CREAT);
    ft_free_tab1(tmp);
    if (fd < 0)
        return (-1);
    close(fd);
    return (0);
}

int         ft_check_redirections(t_cmd *cmd, char *current)
{
    t_cmd   *save;

    save = cmd;
    while (cmd != NULL)
    {
        if (cmd->type == 3 || cmd->type == 4)
        {
            if (check_file(cmd, current) == -1)
                return (ft_error(NULL, PERMISSION_DENIED));
        }
        if (cmd->type == 2)
        {
            if(file_exist(cmd, current) == -1)
                return (ft_error(NULL, NO_FILE_OR_DIR));
        }
        cmd = cmd->next;
    }
    return (0);
}