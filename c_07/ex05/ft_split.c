/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:06:59 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/24 16:07:01 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_sep(char *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count(char *str, char *charset)
{
	int		len_sub;
	int		len_sep;
	int		i;

	len_sub = 0;
	len_sep = 0;
	i = 0;
	while (str[len_sub + len_sep])
	{
		while (is_sep(charset, str[len_sub + len_sep]) 
			&& str[len_sub + len_sep])
			len_sep++;
		if (!is_sep(charset, str[len_sub + len_sep]) 
			&& str[len_sub + len_sep])
			i++;
		while (!is_sep(charset, str[len_sub + len_sep]) 
			&& str[len_sub + len_sep])
			len_sub++;
	}
	return (i);
}

char	*skip(char *str, char *charset, int *len)
{
	int	i;

	i = 0;
	*len = 0;
	while (is_sep(charset, *str) && *str)
		str++;
	while (!is_sep(charset, str[i]) && str[i])
	{
		*len = *len + 1;
		i++;
	}
	return (str);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	char	**out;
	int		i;
	char	*str_temp;

	str_temp = str;
	len = 0;
	i = 0;
	if (str == NULL)
	{
		out = (char **)malloc(1 * sizeof(char *));
		out[0] = NULL;
		return (out);
	}
	out = (char **)malloc((count(str_temp, charset) + 1) * sizeof(char *));
	while (i < count(str_temp, charset))
	{
		str = skip(&str[len], charset, &len);
		out[i] = (char *)malloc((len + 1) * sizeof(char));
		ft_strncpy(out[i], str, len);
		i++;
	}
	out[i] = NULL;
	return (out);
}
/*
int main() {
    char str[] = "   ,   ";
    char charset[] = ",";
    
    char **words = ft_split(str, charset);

    // Printing the split words
    for (int i = 1; words[i - 1] != NULL; i++) {
        printf("Word %d: %s\n", i, words[i - 1]);
    }
    return 0;
}*/
