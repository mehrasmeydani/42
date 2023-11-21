/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:37:25 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 18:48:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putnbr_base(uintptr_t tmp, int cap, int *len, int cases);
int	ft_putchar(char c);
int	ft_putint(int i, int len);
int	ft_putper(const char *s);
int	ft_ph(const char **s, va_list input_ptr);
int	ft_putnum(unsigned int n);
int	ftt_printf(const char *s, va_list input_ptr);
int	ft_printf(const char *s, ...);

#endif