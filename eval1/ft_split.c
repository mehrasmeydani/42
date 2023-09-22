/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:39:59 by seckhard          #+#    #+#             */
/*   Updated: 2023/09/20 16:48:04 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// function is counted
size_t	ft_counter(char const *s, char c)
{
	size_t	onetwothree;

	if (!*s)
		return (0);
	onetwothree = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			onetwothree++;
		while (*s != c && *s)
			s++;
	}
	return (onetwothree);
}

// splits string into substrings
	// allocate memory for the array of strings
	// skips , \t ; : | / space - _ .
	// calculates the length of the current word
	// searches in string s for first encounter of c
char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;
	int		i;

	str = (char **)malloc((ft_counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	str[i] = NULL;
	return (str);
}

/*int main() {
    char input[] = "Hello, World! This is a test.";  // Sample input string
    char delimiter = ' ';  // Delimiter character (space in this case)
    
    // Call the ft_countword function to count substrings
    size_t wordCount = ft_counter(input, delimiter);

    // Print the result
    printf("Number of substrings separated by '%c': %zu\n", delimiter,
		wordCount);

    return (0);
}*/