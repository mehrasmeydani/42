/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsadjina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:21:51 by jsadjina          #+#    #+#             */
/*   Updated: 2023/09/21 13:24:47 by jsadjina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **list, int counter)
{
	while (counter >= 0)
	{
		free(list[counter]);
		counter--;
	}
	free(list);
}

static char	**setarray(char const *str, char **list, char c)
{
	size_t	i;
	int		j;

	j = 0;
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != c && str[i] != '\0')
			i++;
		list[j] = ft_substr(str, 0, i);
		if (list[j] == NULL)
			return (freeall(list, (j - 1)), NULL);
		str += i;
		while (*str == c && c != '\0')
			str++;
		j++;
	}
	list[j] = NULL;
	return (list);
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		words;

	if (!s)
		return (NULL);
	while (*s == c && c)
		s++;
	words = word_count(s, c);
	list = (char **)malloc(sizeof(char *) * (words + 1));
	if (!list)
		return (NULL);
	if (words == 0)
	{
		list[0] = NULL;
		return (list);
	}
	list = setarray(s, list, c);
	return (list);
}
/*
int	main(void)
{
	char	**result = ft_split("tripouille", 0);
	int i = 0;
	while (i < 3)
		printf("{%s} ", result[i++]);
	// while (result[i])
		// printf("{%s} ", result[i++]);
	printf("\n");
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return (0);
}*/
