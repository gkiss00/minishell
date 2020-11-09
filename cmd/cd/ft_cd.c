#include "./../../header/minishell.h"

static void ft_go(t_data *data)
{
    char *tmp;

    tmp = NULL;
    tmp = ft_get_path(data->path, data->cmd_tab[data->a]->arg[0]);
    if(tmp == NULL)
        ft_error(NULL, MALLOC);
    if (ft_does_dir_exist(tmp) == 0)
    {
        free(data->path);
        data->path = tmp;
    }
    else
        ft_error(NULL, NO_FILE_OR_DIR);
    
}

static void ft_go_home(t_data *data)
{
    char    *tmp;
    int     index;

    tmp = NULL;
    index = ft_find_in_env(data->env, "HOME");
    if(index > 0)
    {
        tmp = ft_sub_after_char(data->env[index], '=');
        if (tmp != NULL)
        {
            free(data->path);
            data->path = tmp;
        }
        else
            ft_error(NULL, MALLOC);
    }
    else
        ft_error(NULL, NO_FILE_OR_DIR);
}

void        ft_cd(t_data *data)
{
    if (get_length(data->cmd_tab[data->a]->arg) == 0)
        ft_go_home(data);
    else
        ft_go(data);
}