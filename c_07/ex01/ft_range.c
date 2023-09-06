/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:18:54 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/16 17:18:55 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int			i;
	int			*point;

	if (min >= max)
		return (NULL);
	point = (int *)malloc((max - min) * sizeof(int));
	if (point == 0)
		return (point);
	i = -1;
	while (++i < max - min)
		point[i] = min + i;
	return (point);
}
/*
int main(void)
{
	long int i = 0; 
	int j = 2147483647;
	int d = 0;
	long int s = j - d;
	int *p = ft_range(d , j);
	while (i < s)
	{
		printf("%d\n", p[i]);
		i++;
	}
	return (0);
}*/
