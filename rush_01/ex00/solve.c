/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:14:50 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/16 18:14:51 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define N 4

int	g_cnt = 0;

int		is_visibility_valid(int arr[4][4], char *user_input);
int		processnumber(int grid[N][N], int row, int col, char *user_input);
void	set_0(int (*grid)[4][4]);

int	issafe(int grid[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	printgrid(int grid[N][N])
{
	int		row;
	int		col;
	char	print;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N) 
		{
			print = grid[row][col] + '0';
			write(1, &print, 1);
			if (col < N - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	solve(int grid[N][N], char *user_input)
{
	int	row;
	int	col;

	row = -1;
	while (++row < N)
	{
		col = -1;
		while (++col < N)
		{
			if (grid[row][col] == 0)
				return (processnumber(grid, row, col, user_input));
		}
	}
	return (1);
}

int	processnumber(int grid[N][N], int row, int col, char *user_input)
{
	int	num;

	num = 0;
	while (++num <= N) 
	{
		if (issafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, user_input) && 
				is_visibility_valid(grid, user_input) && g_cnt == 0)
			{
				printgrid(grid);
				g_cnt++;
			}
			grid[row][col] = 0;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	grid[N][N];

	if (argc == 2)
	{
		set_0(&grid);
		solve(grid, argv[1]);
		if (g_cnt == 0)
			write (1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
