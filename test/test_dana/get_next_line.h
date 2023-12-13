/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:59:39 by dstolzle          #+#    #+#             */
/*   Updated: 2023/12/13 13:22:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(int bytes_read, char *s1, char *s2);
int		ft_strchr(char *find_str, char c);
char	*ft_strjoin_2(char *s1, char *s2, int i_size);
char	*ft_read_case(int fd, char *input_line, char *buf);
char	*ft_get_nl(char *input_line);
int 	ft_len(char *s);
char	*cut(char *reeded);
char	*ft_strdup(char *s);





#endif