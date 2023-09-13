/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:17 by codespace         #+#    #+#             */
/*   Updated: 2023/09/13 21:53:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static int	count(char *str, char *charset)
{
	int		len_sub;
	int		len_sep;
	int		i;

	len_sub = 0;
	len_sep = 0;
	i = 0;
	while (str[len_sub + len_sep])
	{
		while (is_sep(charset, str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			len_sep++;
		if (!is_sep(charset, str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			i++;
		while (!is_sep(charset, str[len_sub + len_sep])
			&& str[len_sub + len_sep])
			len_sub++;
	}
	return (i);
}

static char	*skip(char *str, char *charset, int *len)
{
	int	i;

	i = 0;
	*len = 0;
	while (is_sep(charset, *str) && *str)
		str++;
	while (!is_sep(charset, str[i]) && str[i])
	{
		*len = *len + 1;
		i++;
	}
	return (str);
}

static char	**set_free(char **out, int i)
{
	while (--i >= 0)
		free(out[i]);
	free(out);
	return (NULL);
}

char	**ft_split(char *str, char c)
{
	int		len;
	char	**out;
	int		i;
	char	*str_temp;

	str_temp = str;
	len = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	out = (char **)malloc((count(str_temp, &c) + 1) * sizeof(char *));
	if (!out)
		return (out);
	while (i < count(str_temp, &c))
	{
		str = skip(&str[len], &c, &len);
		out[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!out[i])
			return (set_free(out, i));
		ft_strlcpy(out[i], str, len + 1);
		i++;
	}
	out[i] = NULL;
	return (out);
}
