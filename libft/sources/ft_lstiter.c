/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:41:24 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 16:46:29 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	if (!lst)
		return ;
	while (p->next != NULL)
	{
		f(p->content);
		p = p->next;
	}
	f(p->content);
}
