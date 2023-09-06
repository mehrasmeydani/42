/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:23:26 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 17:23:27 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	test(int board[10], int row, int col)
{
	int	a;

	a = -1;
	while (++a < row)
	{
		if (col == board[a] || a + board[a] == row + col 
			|| a - board[a] == row - col)
			return (0);
	}
	return (1);
}

int	ft_ten_queens_rec(int board[10], int *len, int row)
{
	int	a;
	int	b;

	if (row == 10)
	{
		*len += 1;
		b = -1;
		while (++b < 10)
			ft_putchar(board[b] + 48);
		ft_putchar('\n');
	}
	else
	{
		a = -1;
		while (++a < 10)
		{
			if (test(board, row, a))
			{
				board[row] = a;
				ft_ten_queens_rec(board, len, row + 1);
			}
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	a;
	int	l;

	a = -1;
	while (++a < 10)
		board[a] = -1;
	l = 0;
	ft_ten_queens_rec(board, &l, 0);
	return (l);
}
