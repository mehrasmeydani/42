/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperkman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:30:44 by rperkman          #+#    #+#             */
/*   Updated: 2023/07/08 12:27:46 by rperkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line(char st_line, char bd_line, char fn_line, int w)
{
	int	count;

	count = 0;
	ft_putchar(st_line);
	while (count < (w - 2))
	{
		ft_putchar(bd_line);
		count ++;
	}
	if (w > 1)
		ft_putchar(fn_line);
	ft_putchar('\n');
}

void	ft_body(char c, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < h - 2)
	{
		ft_putchar(c);
		j = 0;
		while (j++ < w - 2)
		{
			ft_putchar(' ');
		}
		if (w > 1)
			ft_putchar(c);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_line('A', 'B', 'C', x);
	ft_body('B', x, y);
	if (y > 1)
		ft_line('C', 'B', 'A', x);
}
