/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corentin <corentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:17 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/10 21:37:54 by corentin         ###   ########.fr       */
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

#define MALLOC 1
#define NOT_FOUND 2
#define PARSE 3
#define NO_FILE_OR_DIR 4
#define SYNTAX 5
#define PERMISSION_DENIED 6
#define FORK 7

extern char         **environ;

pid_t	            pid_process;

typedef struct      s_tmp
{
    char            *str;
    int             type;
    struct s_tmp    *next;
}                   t_tmp;

typedef struct      s_cmd
{
    char            *cmd;
    char            **arg;
    int             type;
    int             opt;
    struct s_cmd    *next;
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
    
    struct s_cmd    *cmd;
    struct s_cmd    **cmd_tab;
    int             a;

    int             fd;
    char            *readed;

    int             last_output;
    int             ret;
}                   t_data;


/*
** Utils
*/
char                **ft_sp_split(char *str, char c);
char                *ft_transform(char *str);
char                *ft_tab_join(char **tab, char *str);
char                *ft_get_path(char *current, char *dir);
char                *ft_tomaj(char *str);
char                *ft_sub_after_char(char *str, char c);
char                *ft_sub_before_char(char *str, char c);
/*
** Utils/str
*/
char                *ft_str_delete_segment(char *str, int start, int len);
char                *ft_str_add_segment(char *str, int start, char *segment);
char                *ft_str_replace_segment(char *str, int start, int len, char *segment);
char                *ft_char_to_str(char c);
/*
** Utils/tab
*/
void                ft_print_tab(char **tab);
int                 get_length(char **tab);
char                **ft_add_to_tab(char **tab, char *str);
char                **ft_remove_front_tab(char **tab);
char                **ft_remove_back_tab(char **tab);
char                **ft_remove_from_tab(char **tab, int index);
char                **ft_replace_from_tab(char **tab, char *str, int index);
char                **ft_copy_tab(char **tab);
char                **ft_copy_tab_transformed(char **tab);
char                **ft_join_two_tabs(char **t1, char **t2);
/*
** Utils/file_dir
*/
int                 ft_does_dir_exist(char *path);
int                 ft_does_file_exist(char *path);
/*
** Chain_list
*/
t_cmd               *ft_cmd_new();
t_cmd               *ft_cmd_last(t_cmd *head);
void                ft_cmd_add_back(t_cmd **head, t_cmd *last);
void                ft_print_cmd(t_cmd *head);
t_tmp               *ft_tmp_new();
t_tmp               *ft_tmp_last(t_tmp *head);
void                ft_tmp_add_back(t_tmp **head, t_tmp *last);
void                ft_print_tmp(t_tmp *head);
t_tmp               *ft_tab_to_tmp(char **str);
t_cmd               *ft_tmp_to_cmd(t_tmp *tmp);
/*
** Programme
*/
void                ft_programme(t_data *data);
int                 ft_get_input(t_data *data);
void                ft_get_actions(t_data *data, int i);
void                ft_do_actions(t_data *data);
/*
** Programme/utils
*/
void                ft_reverse_actions(t_data *data);
void                ft_transform_all(t_data *data);
/*
** Options
*/
void                ft_sigint(int n);
void                ft_sigquit(int n);
/*
** Var_env
*/
char                *ft_get_var_env_content(char **env, char *var_env_name);
int                 ft_find_in_env(char **env, char*str);
char                *ft_return_good_env(char **env, int i);
void                ft_check_var_env(t_data* data);
char                *ft_replace_env(t_data *data, char *str, char **env);
/*
** Cmd/pwd
*/
void                ft_pwd(t_data *data);
/*
** Cmd/env
*/
void                ft_env(t_data *data);
/*
** Cmd/exit
*/
void                ft_exit(t_data *data);
/*
** Cmd/echo
*/
void                ft_echo(t_data *data);
/*
** Cmd/export
*/
void                ft_export(t_data *data);
/*
** Cmd/unset
*/
void                ft_unset(t_data *data);
void                ft_unset_arg(t_data *data, char *arg);
/*
** Cmd/cd
*/
void                ft_cd(t_data *data);
/*
** Cmd/exec
*/
void                ft_exec(t_data *data);
/*
** Cmd_options
*/
void                ft_check_options_echo(t_data *data);
/*
** Errors
*/
int			        ft_error(char *str, int i);
int                 ft_check_input(t_data *data);
/*
** Redirections
*/
int                 ft_check_redirections(t_cmd *cmd, char *current);
void                ft_do_redirections(t_data *data);
int                 ft_fork(t_data *data);
/*
** Hub
*/
void                ft_hub(t_data *data, char *cmd);
/*
** Free
*/
void                ft_free_data(t_data *data);
void                ft_free_tmp_data(t_data *data);
void                ft_free_cmd(t_cmd *cmd);
void                ft_free_tmp(t_tmp *cmd);
int                 ft_free_error(t_data *data);
void                ft_free_tab1(char *str);
void                ft_free_tab2(char **tab);
void                ft_free_cmd2(t_cmd **cmd);
int                 ft_free_int(char *str);
#endif