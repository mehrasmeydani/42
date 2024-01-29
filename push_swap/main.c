/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:12:28 by codespace         #+#    #+#             */
/*   Updated: 2024/01/29 14:54:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

long	ft_atol(const char *nptr)
{
	long	i;
	char	sign;

	i = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = *nptr;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i *= 10;
		if (sign == '-')
			i -= (*nptr - 48);
		else
			i += (*nptr - 48);
		nptr++;
	}
	return (i);
}

int	input_check(char *input)
{
	while (*input)
	{
		if ((!ft_isdigit(*input) && !*input == ' ' && !*input == '-'
				&& !*input == '+') || ((*input == '-' || *input == '+')
				&& (!ft_isdigit(*(input + 1)) || !*(input + 1))))
			return (0);
		input++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (tab[0] == 0)
		return ;
	while (tab[i + 1] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (0 < ft_strcmp(tab[i], tab[j]))
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	count(char *str, char charset)
{
	int		len_sub;
	int		len_sep;
	int		i;

	len_sub = 0;
	len_sep = 0;
	i = 0;
	while (str[len_sub + len_sep])
	{
		while ((charset == str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			len_sep++;
		if ((charset != str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			i++;
		while ((charset != str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			len_sub++;
	}
	return (i);
}

int	check(char **input)
{
	int	j;
	int	i;

	i = 0;
	while (input[i + 1])
	{
		j = i + 1;
		while (input[j])
		{
			if (!ft_strcmp(input[j], input[i]) || ft_atoi(input[j])
				!= ft_atol[j] || ft_atoi(input[i]) != ft_atol[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_all(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
}

int	*out_int(char **input, char **sort, int n)
{
	int	i;
	int	j;
	int	*out;

	out = (int *)malloc(sizeof (int) * n);
	if (!out)
		return (NULL);
	i = -1;
	while (input[++i])
	{
		j = -1;
		while (sort[++j])
			if (!ft_strcmp(input[i], sort[j]))
				out[i] = j + 1;
	}
	free_all(sort);
	free_all(input);
	return (out);
}

char	*itobin(int input)
{
	int		i;
	int		tmp;
	char	*out;

	tmp = input;
	i = 0;
	while (tmp != 0)
	{
		tmp /= 2;
		i++;
	}
	out = (char *)ft_calloc(i + 1, 1);
	if (!out)
		return (NULL);
	while (i)
	{
		out[--i] = input % 2;
		input /= 2;
	}
	return (out);
}

char	**to_bin(int *in, int n)
{
	int		i;
	char	**out;

	out = (char **)malloc((n + 1) * sizeof (char *));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		out[i] = itobin(in[i]);
		if (!out[i])
			return (NULL, free_all(out), free(in));
	}
	out[i] = NULL;
	free(in);
	return (out);
}

int	init(t_push_swap *t_in, char *input)
{
	int	i;

	i = -1;
	*t_in->in = ft_split(input, ' ');
	if (!*t_in->in || !check(*t_in->in))
		return (0, free_all(*t_in->in));
	*t_in->sort = ft_split(input, ' ');
	if (!*t_in->sort)
		return (0, free_all(*t_in->in));
	ft_sort_string_tab(*t_in->sort);
	*t_in->nr_el = count(input, ' ');
	*t_in->len_a = *t_in->nr_el;
	*t_in->len_b = 0;
	*t_in->out = out_int(*t_in->in, *t_in->sort, *t_in->nr_el);
	*t_in->stack_a = to_bin(*t_in->out, *t_in->nr_el);
	if (!*t_in->stack_a)
		return (0);
	*t_in->stack_b = (char **)malloc(sizeof(char *) * (*t_in->nr_el + 1));
	if (!*t_in->stack_b)
		return (0, free_all(*t_in->stack_a));
	*t_in->max_len = ft_strlen(*t_in->stack_a[0]);
	while (++i < *t_in->len_a)
		if (*t_in->max_len < ft_strlen(*t_in->stack_a[i]))
			*t_in->max_len = ft_strlen(*t_in->stack_a[i]);
	return (1);
}

int	error(void)
{
	write(1, "Error", 5);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push_swap	name;

	if (argc != 2 || !input_check(argv[1]) || !init(&name, argv[1]))
		return (error());
	
}
