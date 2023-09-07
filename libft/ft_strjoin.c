/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:51:21 by mgardesh          #+#    #+#             */
/*   Updated: 2023/09/07 14:51:22 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (NULL);
	out = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out)
		return (out);
	ft_strlcat(out, s1, ft_strlen(s1) + 1);
	ft_strlcat(out, s2, ft_strlen(s2) + 1);
	return (out);
}
