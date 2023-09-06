/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:10:35 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/13 11:10:36 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	repeat_check(char *str, int *len)
{
	int	i;
	int	j;

	i = 0;
	if (*str == '\0')
		return (1);
	while (str[i + 1])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 1)
		return (1);
	*len = j;
	return (0);
}

int	base_calnlen(char *base)
{
	int	len;
	int	len2;

	len = 0;
	while (base[len])
	{
		if (base[len] > 126 || base[len] < 33 || repeat_check(base, &len2)
			|| base[len] == '+' || base[len] == '-')
			return (0);
		len++;
	}
	return (len);
}

void	ft_putbase(char *base, long int n)
{
	write(1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	tmp;
	long int	basen;

	basen = base_calnlen(base);
	if (base == 0 || basen == 0)
		return ;
	tmp = nbr;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = -tmp;
	}
	if (tmp >= basen)
	{
		ft_putnbr_base(tmp / basen, base);
		ft_putnbr_base(tmp % basen, base);
	}
	else
	{
		ft_putbase(base, tmp);
	}
}
/*
int	main(void)
{
	ft_putnbr_base(-2147483648, "");
	return (0);
}*/
