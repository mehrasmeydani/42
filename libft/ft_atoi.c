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

	i = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		while (*nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i -= (*nptr - 48);
			nptr++;
		}
	}
	else
	{
		if (*nptr == '+')
			nptr++;
		while (*nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i += (*nptr - 48);
			nptr++;
		}
	}
	return (i);
}