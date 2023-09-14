/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:20:39 by codespace         #+#    #+#             */
/*   Updated: 2023/09/14 13:47:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst && del)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp)
			{
				(*del)(tmp->content);
				tmp2 = tmp;
				tmp = tmp->next;
				free(tmp2);
			}
			*lst = 0;
		}
	}
}
