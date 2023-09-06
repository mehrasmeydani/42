/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:52:00 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/15 13:52:01 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index < 0)
		return (-1);
	i = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (i);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%d", ft_fibonacci(atoi(argv[1])));
	}
	return (0);
}*/
