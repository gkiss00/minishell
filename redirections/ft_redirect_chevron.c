#include "./../header/minishell.h"

static void ft_rewrite(t_data *data, t_cmd *cmd)
{
    int     fd;
    int     ret;
    char    buff[10];
    char    *path;

    path = ft_get_path(data->path, cmd->cmd);
    fd = open(path, O_RDONLY);
    ft_free_tab1(data->readed);
    data->readed = NULL;
    while((ret = read(fd, buff, 9)) > 0)
    {
        buff[ret] = '\0';
        data->readed = ft_strjoin_free(data->readed, buff, 1);
    }
    close(fd);
}

void        ft_redirect_chevron(t_data *data)
{
    t_cmd   *cmd;

    cmd = data->cmd_tab[data->a];
    while(cmd)
    {
        if(cmd->type == 2)
            ft_rewrite(data, cmd);
        cmd = cmd->next;
    }
}