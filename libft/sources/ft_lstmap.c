/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:49:11 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 17:59:13 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*tmp;

	p = lst;
	new = ft_lstnew(f(p->content));
	if (!new)
	{
		del(p->content);
		return (NULL);
	}
	while (p->next != NULL)
	{
		p = p->next;
		tmp = ft_lstnew(f(p->content));
		if (!tmp)
		{
			del(p->content);
			return (NULL);
		}
		ft_lstadd_front(&new, tmp);
	}
	return (new);
}
