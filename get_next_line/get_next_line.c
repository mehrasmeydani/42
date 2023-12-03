/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:10:51 by codespace         #+#    #+#             */
/*   Updated: 2023/11/27 13:37:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if ((size == 0 && !dst) || size < ft_strlen(dst))
		return (src_len + size);
	dest_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && ((i + dest_len) < size - 1) && size > 0)
	{
		dst[dest_len + i] = (unsigned char)src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !s*)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((const char)c == s[i])
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*s2;
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	while (src[i])
		i++;
	s2 = (char *)malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s2[i] = src[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void append(char *s, char *s_read)
{
	char	*tmp;
	if (!s)
		s = ft_strdup(tmp);
	else
	{
		tmp = ft_strdup(s);
		free(s);
		s = (char *)malloc(ft_strlen(tmp) + ft_strlen(s_read) + 1);
		if (s == NULL)
			return (NULL);
		ft_strcpy(s, tmp);
		ft_strlcat(s, s_read, ft_strlen(s) + ft_strlen(s_read));
		free(tmp);
		free(s_read);
	}
}

char	*output_till_nl(char **s)
{
	char	*s;

	
}

char *get_next_line(int fd)
{
	static char	*s;
	char		*s_read;
	int			chr_read;

	while (!ft_strchr(s, '\n'))
	{
		s_read = (char *)malloc(BUFFER_SIZE + 1);
		if (!s_read)
			return (NULL);
		chr_read = read(fd, s_read, BUFFER_SIZE);
		if (!chr_read)
		{
			free(s_read);
			return (NULL);
		}
		s_read[BUFFER_SIZE] = '\0';
		append(s, s_read);
	}
	return (output_till_nl(&s));
}