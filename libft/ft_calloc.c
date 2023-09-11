/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:49:02 by mgardesh          #+#    #+#             */
/*   Updated: 2023/09/06 13:50:12 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*out;

	if (nmemb * size == 0 || (nmemb * size) / size != nmemb)
		nmemb = size = 1;
	if (size >= 1 && size <= 8)
	{
		out = (char *)malloc(size * nmemb);
		ft_bzero(out, nmemb * size);
	}
	else 
		return (NULL);
	return ((void *)out);
}
