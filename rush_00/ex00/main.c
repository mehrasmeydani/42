/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperkman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:08:58 by rperkman          #+#    #+#             */
/*   Updated: 2023/07/08 12:36:01 by rperkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	string_to_number(char *str)
{
	int	res;

	res = 0;
	while (*str != 0)
	{
		res = 10 * (*str - 48 + res);
		str++;
	}
	return (res / 10);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "Error: To many or to few arguments", 35);
		return (0);
	}
	rush(string_to_number(argv[1]), string_to_number(argv[2]));
	return (0);
}
