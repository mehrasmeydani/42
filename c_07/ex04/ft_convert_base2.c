/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:14:20 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/20 17:14:22 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*len(char *str, char *base, int *sign, int *len);
int		to_deci(char *str, char *base, int len_base, int *len);

int	base_check(char *base, int *len)
{
	int	i;
	int	j;

	*len = 0;
	while (base[*len])
	{
		if (base[*len] > 126 || base[*len] < 33 || base[*len] == '+'
			|| base[*len] == '-')
			return (0);
		*len = *len + 1;
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
	return (1);
}

void	ft_strcat(char *dest, char src)
{
	int	dest_len;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	dest[dest_len] = src;
	dest[dest_len + 1] = '\0';
}

int	ft_atoi_base(char *str, char *base, int *check)
{
	int		sign;
	int		leng;
	char	*p;
	int		len_base;

	if (base_check(base, &len_base))
	{
		leng = 0;
		sign = 1;
		p = len(str, base, &sign, &leng);
		if (leng != 0)
			*check = 1;
		else
			*check = 0;
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

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	long int	tmp;
	int			basen;

	if (base_check(base, &basen))
	{
		if (basen == 0)
			return ;
		tmp = nbr;
		if (tmp < 0)
		{
			ft_strcat(dest, '-');
			tmp = -tmp;
		}
		if (tmp >= (long int)basen)
		{
			ft_putnbr_base(tmp / (long int)basen, base, dest);
			ft_putnbr_base(tmp % (long int)basen, base, dest);
		}
		else
		{
			ft_strcat(dest, base[tmp]);
		}
	}
}
