/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:24:49 by cochapel          #+#    #+#             */
/*   Updated: 2020/11/14 12:24:38 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void		get_lenght2(char *str, char c, int *i, int k[3])
{
	int		save;

	save = *i;
	while (k[0] == 0 && k[1] == 0 && str[*i] == c && str[*i] && k[2] < 2)
		++*i;
	if (*i > save)
		++k[2];
	while (k[0] == 0 && k[1] == 0 && str[*i] != c
	&& str[*i] != '\'' && str[*i] != '"' && str[*i] && k[2] < 2)
	{
		++k[3];
		++*i;
	}
	while (k[0] == 1 && str[*i] != '"' && str[*i] && k[2] < 2)
	{
		++k[3];
		++*i;
	}
	while (k[1] == 1 && str[*i] != '\'' && str[*i] && k[2] < 2)
	{
		++k[3];
		++*i;
	}
}

static int		get_lenght(char *str, char c, int *i)
{
	int		k[4];

	k[0] = 0;
	k[1] = 0;
	k[2] = 1;
	k[3] = 0;
	while (str[*i] != '\0' && k[2] < 2)
	{
		if (str[*i] == '"' && k[0] == 0 && k[1] == 0 && ++*i && ++k[3])
			k[0] = 1;
		if (str[*i] == '\'' && k[1] == 0 && k[0] == 0 && ++*i && ++k[3])
			k[1] = 1;
		if (str[*i] == '"' && k[0] == 1 && ++*i && ++k[3])
			k[0] = 0;
		if (str[*i] == '\'' && k[1] == 1 && ++*i && ++k[3])
			k[1] = 0;
		get_lenght2(str, c, i, k);
	}
	return (k[3]);
}

static int		get_nb_cell2(char *str, char c, int i, int k[3])
{
	int		save;

	while (k[0] == 1 && str[i] != '"' && str[i])
		++i;
	while (k[1] == 1 && str[i] != '\'' && str[i])
		++i;
	save = i;
	while (k[0] == 0 && k[1] == 0 && str[i] == c && str[i])
	{
		++i;
	}
	if (i > save && str[i] != '\0')
		++k[2];
	while (k[0] == 0 && k[1] == 0 && str[i] != '\''
	&& str[i] != '"' && str[i] != c && str[i])
		++i;
	return (i);
}

static int		get_nb_cell(char *str, char c)
{
	int		i;
	int		k[3];

	i = 0;
	k[0] = 0;
	k[1] = 0;
	k[2] = 0;
	if (str[i] != c && str[i])
		k[2] = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '"' && k[0] == 0 && k[1] == 0 && ++i)
			k[0] = 1;
		if (str[i] == '\'' && k[1] == 0 && k[0] == 0 && ++i)
			k[1] = 1;
		if (str[i] == '"' && k[0] == 1 && ++i)
			k[0] = 0;
		if (str[i] == '\'' && k[1] == 1 && ++i)
			k[1] = 0;
		i = get_nb_cell2(str, c, i, k);
	}
	return (k[2]);
}

char			**ft_sp_split(char *str, char c)
{
	char	**tab;
	char	*tmp;
	char	*str_c;
	int		k[5];
	int		*j;

	k[0] = -1;
	k[3] = 0;
	j = &k[3];
	if ((tab = malloc((get_nb_cell(str, c) + 1) * sizeof(char*))) == NULL)
		return (NULL);
	while (str[*j] == c)
		++*j;
	while (++k[0] < get_nb_cell(str, c))
	{
		k[2] = *j;
		k[4] = get_lenght(str, c, j);
		tmp = ft_substr(str, k[2], k[4]);
		str_c = ft_char_to_str(c);
		tab[k[0]] = ft_strtrim(tmp, str_c);
		free(str_c);
		free(tmp);
	}
	tab[get_nb_cell(str, c)] = NULL;
	return (tab);
}
