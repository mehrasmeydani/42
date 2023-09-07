/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:03 by mgardesh          #+#    #+#             */
/*   Updated: 2023/09/06 16:27:52 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	char	*out;

	lens = ft_strlen(s);
	if (start > lens || len * lens == 0)
		return (NULL);
	if (len + start > lens)
		out = (char *)malloc((lens - start + 1) * sizeof(char));
	else
		out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (out);
	i = start;
	while (s[i + start] && i < len)
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}
