/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:39:18 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 11:53:39 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

# endif

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

float				ft_atof(const char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void *content);
int					ft_nbrlen(int n, int base);
int					ft_putchar_fd_int(char c, int fd);
int					ft_puthex_fd_int(unsigned int n, int fd, int x_case);
int					ft_putstr_fd_int(char *s, int fd);
int					ft_putnbr_fd_int(int n, int fd);
char				*ft_strnjoin_free(char const *s1, char const *s2, int n);
int					ft_unbrlen(size_t n, int base);
char				*ft_strndup(const char *s1, int n);
int					get_next_line(int fd, char **line);
int					ft_strchr_int(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2, int n);
char				*ft_strnjoin(char const *s1, char const *s2, int n);
int					ft_free_tab(char **tab);
int					ft_free_str(char *str);
int					ft_strrchr_int(char *str, char c);

#endif
