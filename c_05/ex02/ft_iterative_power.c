/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:56:21 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/15 12:56:22 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = 1;
	if (power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	while (power > 0)
	{
		a = a * nb;
		power--;
	}
	return (a);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}*/
