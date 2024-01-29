/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:30:51 by mgardesh          #+#    #+#             */
/*   Updated: 2023/12/15 15:35:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	char	sign;

	i = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = *nptr;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i *= 10;
		if (sign == '-')
			i -= (*nptr - 48);
		else
			i += (*nptr - 48);
		nptr++;
	}
	return (i);
}
