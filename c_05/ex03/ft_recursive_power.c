/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:25:22 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/15 13:25:24 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	if (power == 1)
		return (nb);
	a = a * ft_recursive_power(nb, power - 1);
	return (a);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}*/
