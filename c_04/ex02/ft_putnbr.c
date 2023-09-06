/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:05:22 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/07 16:05:31 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr1(void)
{
	char	num[11];

	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	write(1, num, 11);
}

void	ft_putnbr(int nb)
{
	int	tmp;

	if (nb == -2147483648)
	{
		ft_putnbr1();
		return ;
	}
	tmp = nb;
	nb++;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = -tmp;
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
	else
	{
		ft_putchar(tmp + '0');
	}
}
