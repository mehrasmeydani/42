/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:54:19 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/15 18:54:20 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

long int	ft_recursive_power(int nb, int power)
{
	long int	a;

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

int	ft_sqrt(int nb)
{
	int			i;
	long int	tmp;

	tmp = nb;
	i = 0;
	if (nb <= 0)
		return (0);
	while (ft_recursive_power(i, 2) < tmp)
		i++;
	if (ft_recursive_power(i, 2) == tmp)
		return (i);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%d", ft_sqrt(atoi(argv[1])));
	}
	return (0);
}*/
