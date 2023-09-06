/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:41:13 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/17 15:41:14 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long int	i;
	int			*point;
	long int	cnt;

	cnt = 0;
	point = 0;
	i = max - min;
	if (i <= 0)
		return (point);
	point = (int *)malloc(i * sizeof(min));
	while (min < max)
	{
		point[cnt] = min;
		cnt++;
		min++;
	}
	return (point);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long int	j;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	j = (long int)max - (long int)min;
	if (j > 2147483648)
		return (-1);
	i = max - min;
	*range = ft_range(min, max);
	return (i);
}
/*
int	main(void)
{
	int *a[1];
	printf("%d\n", ft_ultimate_range(a, -2000000000, 2000000000));
	
}*/
