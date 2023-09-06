/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:19:28 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/19 14:19:30 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	bullshit(int len)
{
	if (len > 0)
		return (len);
	else
		return (len * -1);
}

int	base_check(char *base)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (base[len])
	{
		if (base[len] > 126 || base[len] < 33 || base[len] == '+'
			|| base[len] == '-')
			return (0);
		len++;
	}
	i = -1;
	while (base[++i + 1])
	{
		j = i;
		while (base[++j])
		{
			if (base[j] == base[i] || base[0] == '\0' )
				return (0);
		}
	}
	if (i < 1)
		return (0);
	return (1);
}

char	*len(char *str, char *base, int *sign, int *len)
{
	int	i;
	int	j;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = *sign * -1;
		str++;
	}
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (str[i] == base [j])
				*len = *len + 1;
		}
		if (*len - 1 != i)
			return (str);
	}
	return (str);
}

int	to_deci(char *str, char *base, int len_base, int *len)
{
	int	res;
	int	i;
	int	j;
	int	power;

	res = 0;
	power = 1;
	i = bullshit(*len);
	while (--i >= 0)
	{
		j = -1;
		while (base[++j])
		{
			if (str[i] == base [j])
			{
				if (*len > 0)
					res = res + (j * power);
				if (*len < 0)
					res = res - (j * power);
				power *= len_base;
			}
		}
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		leng;
	char	*p;
	int		len_base;

	if (base_check(base))
	{
		len_base = -1;
		while (base[++len_base])
			leng = 0;
		sign = 1;
		p = len(str, base, &sign, &leng);
		if (p == NULL)
			return (0);
		else
		{
			leng = leng * sign;
			return (to_deci(p, base, len_base, &leng));
		}
	}
	else
		return (0);
}
/*
int main(void)
{
	printf("%d",ft_atoi_base("", ""));
}*/
