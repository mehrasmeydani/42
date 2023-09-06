/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:00:18 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/12 12:00:22 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_cutstring(char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	str_2_nbr(char *str, int sign)
{
	int	i;

	i = 0;
	if (sign > 0)
	{
		while (*str >= '0' && *str <= '9')
		{
			i *= 10;
			i = i + (*str - 48);
			str++;
		}
	}
	if (sign < 0)
	{
		while (*str >= '0' && *str <= '9')
		{
			i *= 10;
			i = i - (*str - 48);
			str++;
		}
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int		sign;
	char	*p;

	sign = 1;
	p = ft_cutstring(str, &sign);
	return (str_2_nbr(p, sign));
}
