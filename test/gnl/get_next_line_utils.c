/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:15:01 by codespace         #+#    #+#             */
/*   Updated: 2023/12/04 20:22:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			a;
	unsigned char	*p;

	a = 0;
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	p = (unsigned char *)ptr;
	while (a < (size * nmemb))
	{
		p[a] = '\0';
		a++;
	}
	return (ptr);
}

void	ft_strcat(char *dst, char *src)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(dst);
	b = 0;
	while (src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
}

int	ft_strchr(char *s, char c)
{
	if (s == 0)
		return (0);
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
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
