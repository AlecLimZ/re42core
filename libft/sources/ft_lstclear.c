/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:35:28 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 17:54:34 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*h;

	h = *lst;
	while (h->next != NULL)
	{
		ft_lstdelone(h, del);
		h = h->next;
	}
	ft_lstdelone(h, del);
}
