/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:32:06 by dstolzle          #+#    #+#             */
/*   Updated: 2023/12/13 12:18:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_get_feed(char *input_line)
{
	int		i;
	int		j;
	char	*new_line;

	j = 0;
	if (!input_line)
		return (0);
	i = ft_strchr(input_line, 'x');
	while (input_line[i + j])
		j++;
	new_line = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_line)
	{
		free(input_line);
		return (NULL);
	}
	new_line[j] = '\0';
	while (j--)
		new_line[j] = input_line[i + j];
	free(input_line);
	return (new_line);
}

char	*ft_get_nl(char *input_line)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	if (!input_line)
		return (0);
	if (input_line[0] == '\0')
		return (NULL);
	i = ft_strchr(input_line, 'x');
	next_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!next_line)
	{
		free(input_line);
		return (0);
	}
	next_line[i] = '\0';
	j = -1;
	while (++j < i)
		next_line[j] = input_line[j];
	return (next_line);
}

char	*ft_read_case(int fd, char *input_line, char *buf)
{
	int	bytes_read;

	bytes_read = 1;
	while ((bytes_read > 0) && (ft_strchr(input_line, '\n') == 0))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read >= 0)
		{
			buf[bytes_read] = '\0';
			input_line = ft_strjoin(bytes_read, input_line, buf);
			if (!input_line)
				return (0);
		}
		else
		{
			free(buf);
			free(input_line);
			return (0);
		}
	}
	free(buf);
	return (input_line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*input_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(input_line);
		input_line = NULL;
		return (NULL);
	}
	input_line = ft_read_case(fd, input_line, buf);
	if (!input_line)
		return (NULL);
	next_line = ft_get_nl(input_line);
	if (!next_line)
		return (input_line = NULL, NULL);
	input_line = ft_get_feed(input_line);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	char *s;
// 	int fd = open("file.txt", O_RDONLY);
// 	do
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);
// 	} while (s);
// }
