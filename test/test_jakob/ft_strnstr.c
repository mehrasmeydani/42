/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:46:08 by jsadjina          #+#    #+#             */
/*   Updated: 2023/09/22 11:07:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1 = s1;
	const unsigned char	*str2 = s2;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_1strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!big && len == 0) || (len < ft_strlen(little) && !ft_strlen(big)))
		return (NULL);
	if (!*little && big)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*string;
	char	*small;
	size_t	i;
	size_t	j;

	string = (char *)big;
	small = (char *)little;
	i = 0;
	j = ft_strlen(small);
	if (j == 0)
		return (string);
	while (i < len && string[i] != '\0')
	{
		if (string[i] == small[0])
		{
			if (ft_memcmp(&string[i], small, j) == 0 && (i + j) <= len)
				return (&string[i]);
		}
		i++;
	}
	return (0);
}

#include <bsd/string.h>
#include <stdio.h>

int main()
{
    char str1[6] = {288 ,48, -128, 50, 1, 0};
    char str2[5] = {32, 48, 128, 50, 0};
    // Test the custom strnstr function against the actual strnstr function
    printf("%s\n%s\n%s\n",ft_strnstr(str1, str2, 4),ft_1strnstr(str1, str2, 4), strnstr(str1, str2, 4));
    return 0;
}