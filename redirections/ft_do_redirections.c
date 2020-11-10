#include "./../header/minishell.h"

static void ft_read_fd(int fd)
{
    int     buff[10];
    int     ret;

    while((ret = read(fd, buff, 10)) > 0)
    {

    }
}

static void ft_redirect(t_data *data, t_cmd *cmd)
{
    int     fd;
    char    *path;

    path = ft_get_path(data->path, cmd->cmd);
    //puts(path);
    fd = open(path, O_RDONLY | O_WRONLY);
    free(path);
    printf("%d\n", fd);
    if(cmd->type == 4)
        ft_read_fd(fd);
    dup2(fd, 1);
    close(fd);
}

void        ft_do_redirections(t_data *data)
{
    t_cmd   *cmd;

    cmd = data->cmd_tab[data->a];
    while(cmd)
    {
        if (cmd->type == 3 || cmd->type == 4)
            ft_redirect(data, cmd);
        cmd = cmd->next;
    }
}