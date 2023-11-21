/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:38:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 18:47:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (s == 0)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putnbr_base(uintptr_t tmp, int cap, int *len, int cases)
{
	const char	*base[2] = {"0123456789abcdef", "0123456789ABCDEF"};

	if (tmp == 0 && cases == 0 && *len == 1)
		return (ft_putstr("(nil)"));
	if (*len == 1 && cases == 0)
		*len += ft_putstr("0x");
	if (tmp >= 16)
	{
		*len += 1;
		ft_putnbr_base(tmp / 16, cap, len, cases);
		ft_putnbr_base(tmp % 16, cap, len, cases);
	}
	else
		write(1, &base[cap][tmp], 1);
	return (*len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putint(int i, int len)
{
	char	*s;

	s = ft_itoa(i);
	len = ft_putstr(s);
	free(s);
	return (len);
}
