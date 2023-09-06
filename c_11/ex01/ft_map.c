/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:09:26 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 00:09:27 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*j;

	i = -1;
	j = (int *)malloc(length * sizeof(int));
	while (++i < length)
		j[i] = (*f)(tab[i]);
	return (j);
}
