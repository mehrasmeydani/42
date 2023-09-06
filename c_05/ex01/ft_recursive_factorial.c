/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:52:00 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/14 12:52:03 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	int	a;

	a = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	a = nb * ft_recursive_factorial(nb - 1);
	return (a);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%d", ft_recursive_factorial(atoi(argv[1])));
	}
	return (0);
}*/
