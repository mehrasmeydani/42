/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:45:55 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 04:45:56 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	check(char op)
{
	char	*p;
	int		a;

	p = "+-/*%";
	a = 0;
	while (p[a] != '\0')
	{
		if (op == p[a])
			return (a);
		a++;
	}
	return (5);
}

int	zero(int v2, int a)
{
	if (v2 == 0 && a == 2)
	{
		write(1, "Stop : division by zero\n", 24);
		return (5);
	}
	else if (v2 == 0 && a == 4)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (5);
	}
	return (0);
}

int	oper(int v1, int v2, int a)
{
	int	(*p[5])(int val1, int val2);

	p[0] = sum;
	p[1] = sub;
	p[2] = div;
	p[3] = mul;
	p[4] = rem;
	return ((*p[a])(v1, v2));
}

char	bullshit(char op, int v1, int v2, int *res)
{
	if (check(op) != 5)
	{
		if (zero(v2, check(op)) == 0)
		{
			*res = oper(v1, v2, check(op));
			return ('1');
		}
		return ('2');
	}
	else
		return ('0');
}
