#include "../../header/minishell.h"

static int  ft_is_path_valid(char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) == 0)
        return (1);
    return (0);
}

static char **ft_get_path_content(char **env)
{
    char    *path_content;
    char    **paths;

   
    if ((path_content = ft_get_var_env_content(env, "PATH")) == NULL)
        return (NULL);
    if ((paths = ft_split(path_content, ':')) == NULL)
    {
        free(path_content);
        return (NULL);
    }
    free(path_content);
    return (paths);
}

static char *ft_find_path_from_env(t_data *data, char *str)
{
    char    *path;
    char    **paths;
    int     i;

    if ((paths = ft_get_path_content(data->env)) == NULL)
        return (NULL);
    i = 0;
    while (paths[i] != NULL)
    {
        if ((path = ft_strjoin(paths[i], str)) == NULL)
            return (NULL);
        if (ft_is_path_valid(path) == 1)
            return (path);
        ++i;
    }
    return (NULL);
}

static char *ft_find_path(t_data *data, char *str)
{
    char    *path;

    if (str[0] == '/')
        path = ft_strdup(str);
    else if ((path = ft_find_path_from_env(data, str)) == NULL)
        path = ft_strjoin(ft_get_var_env_content(data->env, "PWD"), str);

    if (ft_is_path_valid(path) == 1)
        return (path);
    free(path);
    return (NULL);
}

void        ft_exec(t_data *data)
{
    char    *path;
    char    **args;
    char    **env;

    if (data->cmd_tab[data->a]->arg[0] == NULL)
        return ;
    if ((path = ft_find_path(data, data->cmd_tab[data->a]->arg[0])) == NULL)
    {
        ft_putstr_fd("ERROR\n", 1);
    }
    args = ft_copy_tab(data->cmd_tab[data->a]->arg);
    env = ft_copy_tab(data->env);
    execve(path, args, env);

    free(path);
    ft_free_tab2(args);
    ft_free_tab2(env);
}