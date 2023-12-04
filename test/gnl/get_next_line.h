/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:35 by ajordan-          #+#    #+#             */
/*   Updated: 2023/12/04 15:31:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
void	ft_strcat(char *dst, char *src);
char	*get_next_line(int fd);
char	*readfile(int fd, char *tmp, char *reeded);
char	*append(char *reeded, char *tmp);
char	*line(char *reeded);
char	*cut(char *reeded);
char	*null_all(char *st, char *s);

#endif