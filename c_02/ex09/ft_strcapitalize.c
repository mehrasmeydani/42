/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:10:14 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/09 12:10:16 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char str)
{
	if (!((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')))
		return (0);
	return (1);
}

int	ft_char_is_numeric(char str)
{
	if (str < '0' || str > '9')
		return (0);
	return (1);
}

int	ft_char_is_lowercase(char str)
{
	if (!(str >= 'a' && str <= 'z'))
		return (0);
	return (1);
}

int	ft_char_is_uppercase(char str)
{
	if (!(str >= 'A' && str <= 'Z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (!(ft_char_is_alpha(str[i]) || ft_char_is_numeric(str[i])))
			i++;
		if (ft_char_is_uppercase(str[i]))
			i++;
		else if (ft_char_is_lowercase(str[i]))
		{
			str[i] -= 32;
			i++;
		}
		while ((ft_char_is_alpha(str[i]) || ft_char_is_numeric(str[i])))
		{
			if (ft_char_is_uppercase(str[i]))
				str[i] += 32;
			i++;
		}
	}
	return (str);
}
