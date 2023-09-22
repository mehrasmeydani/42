/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:02:07 by seckhard          #+#    #+#             */
/*   Updated: 2023/09/18 18:45:06 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split_next
{
	size_t			start;
	size_t			length;
}					t_split_next;

//Libc functions
char				*ft_strchr(const char *str, int character);
char				*ft_strrchr(const char *str, int character);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *s);

void				*ft_memset(void *buf, int val, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *to, const void *from, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int x, size_t n);
void				*ft_calloc(size_t numb, size_t size);

int					ft_isalpha(int a);
int					ft_isdigit(int c);
int					ft_isalnum(int y);
int					ft_isprint(int b);
int					ft_toupper(int a);
int					ft_tolower(int x);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
int					ft_atoi(const char *str);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

//Additional functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif