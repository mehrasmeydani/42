/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:29:36 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/07 16:29:39 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	set_0(char *p)
{
	int	a;

	a = 0;
	while (a < 10)
	{
		p[a] = '0';
		a++;
	}
}

void	ft_putsp(void)
{
	write(1, ", ", 2);
}

void	ft_putarr(const void *buf, int n)
{
	write(1, buf, n);
}

void	loop_n(char *p, int n, int n_main, int sub_n)
{
	while (p[n - 1] <= ('9' - (n_main - n)))
	{
		p[n] = p[n - 1] + 1;
		if (n == n_main)
		{
			while (p[n - 1] <= '9')
			{
				ft_putarr(p, n_main);
				if (p[0] != ('9' - (n_main - sub_n)))
					ft_putsp();
				p[n - 1]++;
			}
			return ;
		}
		else
		{
			loop_n (p, n + 1, n_main, sub_n);
		}
		p[n - 1]++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	num[10];
	int		n_sub;

	set_0(num);
	n_sub = 1;
	num[0] = '0';
	loop_n(num, n_sub, n, n_sub);
	return ;
}
