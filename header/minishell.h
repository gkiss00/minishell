/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:17 by cochapel          #+#    #+#             */
/*   Updated: 2020/10/11 17:12:51 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** External functions :
**
** malloc, free, write, open, read, close, fork, wait,
** waitpid, wait3, wait4, signal, kill, exit, getcwd,
** chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
** opendir, readdir, closedir, strerror, errno
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"

extern char         **environ;

//const int MALLOC_ERROR = 1;

typedef struct      s_cmd
{
    char            *cmd;
    char            **arg;
    int             type;
    struct s_cmd   *next;
}                   t_cmd;

typedef struct      s_data
{
    int             i1;
    int             i2;
    int             i3;

    int             c1;
    int             c2;

    char            *tmp;
    char            **tab_tmp;

    char            **env;
    char            *path;

    int             gnl_ret;
    char            *gnl_line;
    char            *gnl_tmp;

    char            **tabinput;
    
    struct s_cmd   *cmd;

    int             last_output;
    int             ret;
}                   t_data;


/*
** Utils
*/
char                **ft_sp_split(char *str, char c);
char                **ft_add_to_tab(char **tab, char *str);
int                 get_length(char **tab);
/*
** Chain_list
*/
t_cmd               *ft_new();
void                ft_add_back(t_cmd *head, t_cmd *last);
/*
** Programme
*/
void                ft_programme(t_data *data);
void                ft_listen(t_data *data);
int                 ft_get_input(t_data *data);
void                ft_do_actions(t_data *data);
/*
** Options
*/
void                ft_sigint(int n);
void                ft_sigquit(int n);
/*
** Errors
*/
int			        ft_error(char *str, int i);
/*
** Free
*/
void                ft_free_data(t_data *data);
void                ft_free_tmp_data(t_data *data);
void                ft_free_cmd(t_cmd *cmd);
int                 ft_free_error(t_data *data);
void                ft_free_tab1(char *str);
void                ft_free_tab2(char **tab);
#endif