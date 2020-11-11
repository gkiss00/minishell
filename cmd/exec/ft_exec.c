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
    char    backslash[2];
    int     i;

    if ((paths = ft_get_path_content(data->env)) == NULL)
        return (NULL);
    backslash[0] = '/';
    backslash[1] = '\0';
    i = 0;
    while (paths[i] != NULL)
    {
        if ((path = ft_strjoin(paths[i], backslash)) == NULL)
            return (NULL);
        if ((path = ft_strjoin(path, str)) == NULL)
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
    char    *tmp;
    char    *tmp2;
    char    backslash[2];

    backslash[0] = '/';
    backslash[1] = '\0';
    if (str[0] == '/' && (path = ft_strdup(str)) == NULL)
        return (NULL);
    else if ((path = ft_find_path_from_env(data, str)) == NULL)
    {
        if ((tmp = ft_get_var_env_content(data->env, "PWD")) == NULL)
            return (NULL);
        if ((tmp2 = ft_strjoin(tmp, backslash)) == NULL && ft_free_int(tmp))
            return (NULL);
        if ((path = ft_strjoin(tmp2, str)) == NULL && ft_free_int(tmp) && ft_free_int(tmp2))
            return (NULL);
        free(tmp);
        free(tmp2);
    }
    if (ft_is_path_valid(path) == 1)
        return (path);
    free(path);
    return (NULL);
}

static char **ft_get_execve_args(char *cmd, char **args)
{
    char    *cmd_tab[2];
    char    **tmp;
    char    **ret;

    if ((cmd_tab[0] = ft_strdup(cmd)) == NULL)
        return (NULL);
    cmd_tab[1] = NULL;
    if ((tmp = ft_copy_tab(args)) != NULL)
    {
        if ((ret = ft_join_two_tabs(cmd_tab, tmp)) == NULL && ft_free_int(cmd_tab[0]))
            return (NULL);
        ft_free_tab2(tmp);
    }
    else if ((ret = ft_copy_tab(cmd_tab)) == NULL && ft_free_int(cmd_tab[0]))
        return (NULL);
    free(cmd_tab[0]);
    return (ret);
}

static int  ft_wait_a_little(char *str)
{
    int i;
    int j;

    if (str == NULL)
        return (1);
    i = 0;
    while (str[i] != 0)
    {
        j = 0;
        while (j < 1000)
            ++j;
        ++i;
    }
    return (0);
}

void        ft_exec(t_data *data)
{
    char    *path;
    int     fd2[2];

    if ((path = ft_find_path(data, data->cmd_tab[data->a]->cmd)) == NULL)
    {
        ft_error(data->cmd_tab[data->a]->cmd, EXEC);
        return ;
    }
        pipe(fd2);
        if ((pid_process = fork()) == 0)
        {
            if (data->readed != NULL)
                dup2(fd2[0], 0);
            chdir(ft_get_var_env_content(data->env, "PWD"));
		    execve(path, ft_get_execve_args(data->cmd_tab[data->a]->cmd, data->cmd_tab[data->a]->arg), ft_copy_tab(data->env));
            exit(0);
        }
        else
        {
            if (data->readed != NULL)
            {
                ft_putstr_fd(data->readed, fd2[1]);
                ft_wait_a_little(data->readed);
                kill(pid_process, SIGQUIT);
            }
            else
            {
                wait(NULL);
            }
            data->last_output = WEXITSTATUS(pid_process);
            pid_process = -1;
            free(path);
        }
}