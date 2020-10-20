#include "../header/minishell.h"

static char *get_racine()
{
    char    *path;

    path = ft_strdup("/");
    return (path);
}

static char *get_absolute_path(char **tab)
{
    int     i;
    char    *path;

    i = 0;
    while(tab != NULL && tab[i] != NULL)
    {
        if (ft_strcmp(tab[i], ".") == 0)
        {
            tab = ft_remove_from_tab(tab, i);
            i = -1;
        }
        else if (ft_strcmp(tab[i], "..") == 0)
        {
            tab = ft_remove_from_tab(tab, i);
            tab = ft_remove_from_tab(tab, i - 1);
            i = -1;
        }
        ++i;
    }
    path = ft_tab_join(tab, "/");
    ft_free_tab2(tab);
    return (path);
}

static char *get_path_from_here(char *current, char *dir)
{
    char    **t1;
    char    **t2;
    char    **t3;

    t1 = ft_split(current, '/');
    t2 = ft_split(dir, '/');
    t3 = ft_join_two_tabs(t1, t2);
    ft_free_tab2(t1);
    ft_free_tab2(t2);
    return (get_absolute_path(t3));
}

static char *get_path_from_racine(char *dir)
{
    char    **tab;

    tab = ft_split(dir, '/');
    return (get_absolute_path(tab));
}

char        *ft_get_path(char *current, char *dir)
{
    char *path;

    path = NULL;
    if (current == NULL || dir == NULL)
        return (NULL);
    if (dir[0] == '/')
        path = get_path_from_racine(dir);
    else
        path = get_path_from_here(current, dir);
    if (path && ft_strlen(path) == 0)
    {
        ft_free_tab1(path);
        path = get_racine();
    }
    return (path);
}