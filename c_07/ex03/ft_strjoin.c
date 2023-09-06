/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:33 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/17 17:32:35 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	calculate_total_length(char **strs, char *sep, int size)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
			total_length += ft_strlen(strs[i]);
		if (i < size - 1 && sep != NULL)
			total_length += ft_strlen(sep);
		i++;
	}
	return (total_length);
}

void	copy_strings(char *result_str, char **strs, char *sep, int size)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			ft_strcpy(result_str + pos, strs[i]);
			pos += ft_strlen(strs[i]);
		}
		if (i < size - 1 && sep != NULL)
		{
			ft_strcpy(result_str + pos, sep);
			pos += ft_strlen(sep);
		}
		i++;
	}
	result_str[pos] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*empty_str;
	int		total_length;
	char	*result_str;

	if (size <= 0)
	{
		empty_str = (char *)malloc(sizeof(char));
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	total_length = calculate_total_length(strs, sep, size) + 1;
	result_str = (char *)malloc(total_length * sizeof(char));
	if (result_str == NULL)
		return (NULL);
	copy_strings(result_str, strs, sep, size);
	return (result_str);
}
/*
int main(void)
{
    char *a[] = {};
    char *b = 0;
    char *result = ft_strjoin(-1, a, b);
    if (result)
    {
        printf("%s", result);
        free(result);
    }
    return 0;
}*/
