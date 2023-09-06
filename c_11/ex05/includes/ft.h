/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:38:54 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 16:40:55 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

char	*ft_count(char *pstr, int *b);
int		ft_atoi(char *str);
void	ft_putchar(char a);
void	ft_putnbr(int nb);
int		sum(int val1, int val2);
int		sub(int val1, int val2);
int		div(int val1, int val2);
int		mul(int val1, int val2);
int		rem(int val1, int val2);
int		check(char op);
int		zero(int v2, int a);
int		oper(int v1, int v2, int a);
char	bullshit(char op, int v1, int v2, int *res);

#endif
