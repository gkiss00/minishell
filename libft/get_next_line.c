/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochapel <cochapel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:22:07 by cochapel          #+#    #+#             */
/*   Updated: 2020/02/13 15:53:23 by cochapel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != 0)
		++i;
	while (s2 && s2[j] != 0 && s2[j] != '\n')
		++j;
	if (!(tab = malloc(i + j + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[j] != 0)
		tab[i++] = s1[j++];
	j = 0;
	while (s2 != NULL && s2[j] != 0 && s2[j] != '\n')
		tab[i++] = s2[j++];
	tab[i] = 0;
	free(s1);
	return (tab);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (line == NULL || fd < 0 || BUFFER_SIZE == 0 || fd > FOPEN_MAX)
		return (-1);
	if ((line[0] = ft_strjoin_gnl(NULL, buf[fd])) == NULL)
		return (-1);
	ret = 1;
	while (ft_strchr_int(buf[fd], '\n') == -1 && ret != 0)
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[fd][ret] = 0;
		if (!(line[0] = ft_strjoin_gnl(line[0], buf[fd])))
			return (-1);
	}
	ret = ft_strchr_int(buf[fd], '\n') + 1;
	if ((i = 0) == 0 && buf[fd][0] == 0)
		return (0);
	while (buf[fd][ret] != 0 && ret != 0)
		buf[fd][i++] = buf[fd][ret++];
	buf[fd][i] = 0;
	return (1);
}
