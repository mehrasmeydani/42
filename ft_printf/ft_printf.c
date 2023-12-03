/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:17 by mgardesh          #+#    #+#             */
/*   Updated: 2023/11/21 18:46:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putper(const char *s)
{
	if (*(s - 1) == ' ')
	{
		ft_putstr("% ");
		ft_putchar(*s);
		return (3);
	}
	else
	{
		ft_putchar('%');
		ft_putchar(*s);
		return (2);
	}
}

int	ft_putnum(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnum(n / 10);
		len += ft_putnum(n % 10);
	}
	else
	{
		len++;
		ft_putchar_fd(n + 48, 1);
	}
	return (len);
}

int	ft_ph(const char **s, va_list input_ptr)
{
	int	len;

	len = 1;
	while (**s == ' ')
		*s += 1;
	if (**s == 'c')
		return (ft_putchar((char)va_arg(input_ptr, int)));
	else if (**s == 's')
		return (ft_putstr(va_arg(input_ptr, char *)));
	else if (**s == 'p')
		return (ft_putnbr_base(va_arg(input_ptr, uintptr_t), 0, &len, 0));
	else if (**s == 'd' || **s == 'i')
		return (ft_putint(va_arg(input_ptr, int), len));
	else if (**s == 'u')
		return (ft_putnum((int)va_arg(input_ptr, unsigned int)));
	else if (**s == 'x')
		return (ft_putnbr_base(va_arg(input_ptr, unsigned int), 0, &len, 1));
	else if (**s == 'X')
		return (ft_putnbr_base(va_arg(input_ptr, unsigned int), 1, &len, 1));
	else if (**s == '%')
		return (ft_putchar('%'));
	else
		return (ft_putper(*s));
}

int	ftt_printf(const char *s, va_list input_ptr)
{
	int	len;

	len = 0;
	while (s && *s)
	{
		if (*s == '%')
		{
			s++;
			len += ft_ph(&s, input_ptr);
		}
		else
		{
			write(1, s, 1);
			len++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	input_ptr;
	int		len;

	va_start(input_ptr, s);
	len = ftt_printf(s, input_ptr);
	va_end(input_ptr);
	return (len);
}
