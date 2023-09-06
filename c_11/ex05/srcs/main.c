/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:45:34 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 04:45:37 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	main(int argc, char *argv[])
{
	int	b;
	int	c;
	int	res;

	if (argc != 4)
		return (0);
	if (argv[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	b = ft_atoi(argv[1]);
	c = ft_atoi(argv[3]);
	if (bullshit(argv[2][0], b, c, &res) == '2')
		return (0);
	else if (bullshit(argv[2][0], b, c, &res) == '0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
