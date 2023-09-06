/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:29:43 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/16 16:29:45 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*s2;
	int		i;

	i = 0;
	while (src[i])
		i++;
	s2 = (char *)malloc((i + 1) * sizeof(char));
	return (ft_strcpy(s2, src));
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n%s", ft_strdup(argv[1]), strdup(argv[1]));
	}
}*/
