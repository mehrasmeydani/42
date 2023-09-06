/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:30:51 by mgardesh          #+#    #+#             */
/*   Updated: 2023/09/06 11:43:03 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	i = 0;
	if (nptr[0] != '-')
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i = i + (*nptr - 48);
			nptr++;
		}
	}
	else
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i = i - (*nptr - 48);
			nptr++;
		}
	}
	return (i);
}
