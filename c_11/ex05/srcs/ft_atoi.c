/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:44:21 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 04:44:23 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

char	*ft_count(char *pstr, int *b)
{
	while (*pstr == 32 || (*pstr >= 9 && *pstr <= 13))
		pstr++;
	while (*pstr == '-' || *pstr == '+')
	{
		if (*pstr == '-')
			*b *= -1;
		pstr++;
	}
	return (pstr);
}

int	ft_atoi(char *str)
{
	int		b;
	int		c;
	char	*p;

	b = 1;
	p = ft_count(str, &b);
	c = 0;
	while (*p >= '0' && *p <= '9')
	{
		c *= 10;
		if (b == -1)
			c -= (*p - 48);
		else
			c += (*p - 48);
		p++;
	}
	return (c);
}
