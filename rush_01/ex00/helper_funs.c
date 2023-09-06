/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:53:09 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/16 17:53:11 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	asign(int *dr, int *dc)
{
	dr[0] = -1;
	dr[1] = 0;
	dr[2] = 1;
	dr[3] = 0;
	dc[0] = 0;
	dc[1] = 1;
	dc[2] = 0;
	dc[3] = -1;
}

int	count_visible(int arr[4][4], int row, int col, int dir)
{
	int	dr[4]; 
	int	dc[4];
	int	i;
	int	count_vis;
	int	max;

	asign(dr, dc);
	i = 0;
	count_vis = 0;
	max = 0;
	while (i < 4) 
	{
		if (arr[row][col] > max) 
		{
			max = arr[row][col];
			count_vis++;
		}
		col = col + dc[dir];
		row = row + dr[dir];
		i++;
	}
	return (count_vis);
}

void	ft_cat(char *dest, char src)
{
	int	i; 

	i = 0;
	while (dest[i])
		i++;
	dest[i] = src;
	dest[i + 1] = '\0';
}

int	str_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return (str1[i] - str2[i]); 
}

void	set_null(char *vis_res, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		vis_res[i] = '\0';
		i++;
	}
}
