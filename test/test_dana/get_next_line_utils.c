/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:55:41 by dstolzle          #+#    #+#             */
/*   Updated: 2023/12/13 13:19:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_2(char *s1, char *s2, int i_size)
{
	char	*c_s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	c_s3 = (char *)malloc(sizeof(char) * i_size);
	if (!c_s3)
	{
		free(s1);
		free(s2);
		return (0);
	}
	while (s1[i])
	{
		c_s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		c_s3[i++] = s2[j++];
	c_s3[i] = '\0';
	free(s1);
	return (c_s3);
}

char	*ft_strjoin(int bytes_read, char *input_line, char *buf)
{
	int		len_input_line;
	char	*c_s3;
	int		i;

	i = 0;
	len_input_line = 0;
	if (!input_line)
	{
		c_s3 = malloc(sizeof(char) * (ft_len(buf) + 2));
		if (!c_s3)
		{
			free(buf);
			return (0);
		}
		while (i < ft_len(buf))
		{
			c_s3[i] = buf[i];
			i++;
		}
		c_s3[i] = '\0';
		return (c_s3);
	}
	while (input_line[len_input_line])
		len_input_line++;
	return (ft_strjoin_2(input_line, buf, (len_input_line + bytes_read + 1)));
}

int	ft_strchr(char *find_str, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		if (!find_str)
			return (0);
		while (find_str[i])
		{
			if (find_str[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
	{
		while (find_str[i])
		{
			if (find_str[i] == '\n')
				return (i + 1);
			i++;
		}
		return (i);
	}
}

int ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}