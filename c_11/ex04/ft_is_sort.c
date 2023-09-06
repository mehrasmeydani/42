/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:09:55 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 01:09:57 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	while (tmp == 0 && ++i < length - 1)
		if ((*f)(tab[i], tab[i + 1]) != 0)
			tmp = (*f)(tab[i], tab[i + 1]);
	i = -1;
	while (++i < length - 1)
		if ((((*f)(tab[i], tab[i + 1]) < 0 && tmp > 0)
			|| ((*f)(tab[i], tab[i + 1]) > 0 && tmp < 0)) && tmp != 0)
			return (0);
	return (1);
}
