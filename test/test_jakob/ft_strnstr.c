/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsadjina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:46:08 by jsadjina          #+#    #+#             */
/*   Updated: 2023/09/19 12:37:48 by jsadjina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char big[] = "asdad";
	char little[] = "as";
	int len = 2;
	char *result;

	result = ft_strnstr(big, little, len);

	printf("%s\n", result);
//	printf("%s", result);
	return(0);
}
*/
