/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glibardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:39:05 by glibardi          #+#    #+#             */
/*   Updated: 2023/07/16 15:49:01 by glibardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_visible(int arr[4][4], int row, int col, int dir);
void	ft_cat(char *dest, char src);
int		str_cmp(char *str1, char *str2);

void	append_top_edge(int arr[4][4], char *vis_res)
{
	int	j;
	int	visible_count;

	j = 0;
	while (j < 4)
	{
		visible_count = count_visible(arr, 0, j, 2);
		ft_cat(vis_res, visible_count + '0');
		ft_cat(vis_res, ' ');
		j++;
	}
}

void	append_bottom_edge(int arr[4][4], char *vis_res)
{
	int	j;
	int	visible_count;

	j = 0;
	while (j < 4)
	{
		visible_count = count_visible(arr, 3, j, 0);
		ft_cat(vis_res, visible_count + '0');
		ft_cat(vis_res, ' ');
		j++;
	}
}

void	append_left_edge(int arr[4][4], char *vis_res)
{
	int	j;
	int	visible_count;

	j = 0;
	while (j < 4)
	{
		visible_count = count_visible(arr, j, 0, 1);
		ft_cat(vis_res, visible_count + '0');
		ft_cat(vis_res, ' ');
		j++;
	}
}

void	append_right_edge(int arr[4][4], char *vis_res)
{
	int	j;
	int	visible_count;

	j = 0;
	while (j < 4) 
	{
		visible_count = count_visible(arr, j, 3, 3);
		ft_cat(vis_res, visible_count + '0');
		if (j < 3)
			ft_cat(vis_res, ' ');
		j++;
	}
}
