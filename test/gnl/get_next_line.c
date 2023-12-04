/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:09:06 by jdecorte          #+#    #+#             */
/*   Updated: 2023/12/04 15:34:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reeded;
	char		*next_line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
	{
		free(reeded);
		reeded = NULL;
		return (NULL);
	}
	reeded = readfile(fd, tmp, reeded);
	if (!reeded)
		return (NULL);
	next_line = line(reeded);
	if (!next_line)
		return (NULL);
	reeded = cut(reeded);
	return (next_line);
}

char	*readfile(int fd, char *tmp, char *reeded)
{
	int		charlen;

	charlen = 1;
	if (!tmp)
		return (NULL);
	while (charlen > 0 && ft_strchr(reeded, '\n') == 0)
	{
		charlen = read(fd, tmp, BUFFER_SIZE);
		if (charlen < 0)
		{
			free(reeded);
			reeded = NULL;
			free(tmp);
			return (NULL);
		}
		if (charlen == 0)
			break ;
		tmp[charlen] = '\0';
		reeded = append(reeded, tmp);
		if (reeded == NULL)
			return (NULL);
	}
	free(tmp);
	return (reeded);
}

char	*append(char *reeded, char *tmp)
{
	char	*all;

	if (reeded == 0)
	{
		reeded = ft_strdup(tmp);
		if (!reeded && tmp)
			free(tmp);
		return (reeded);
	}
	all = ft_calloc(ft_strlen(reeded) + BUFFER_SIZE + 1, 1);
	if (all == NULL)
	{
		free(reeded);
		reeded = NULL;
		free(tmp);
		return (NULL);
	}
	ft_strcat(all, reeded);
	ft_strcat(all, tmp);
	free(reeded);
	reeded = NULL;
	return (all);
}

char	*line(char *reeded)
{
	char	*next_line;
	int		a;

	a = 0;
	while (reeded[a] != '\0' && reeded[a] != '\n')
		a++;
	if (reeded[a] == '\0')
	{
		next_line = ft_strdup(reeded);
		return (next_line);
	}
	next_line = malloc(a + 2);
	if (next_line == NULL)
	{
		free(reeded);
		reeded = NULL;
		return (NULL);
	}
	a = -1;
	while (reeded[++a] != '\n')
		next_line[a] = reeded[a];
	next_line[a] = '\n';
	next_line[a + 1] = '\0';
	return (next_line);
}

char	*cut(char *reeded)
{
	char	*tmp;
	int		a;

	a = 0;
	while (reeded[a] != '\0' && reeded[a] != '\n')
		a++;
	if (reeded[a] == '\0')
	{
		free(reeded);
		reeded = NULL;
		return (NULL);
	}
	a++;
	if (reeded[a] != '\0')
		tmp = ft_strdup(&reeded[a]);
	else
	{
		free(reeded);
		reeded = NULL;
		return (NULL);
	}
	free(reeded);
	reeded = NULL;
	return (tmp);
}
