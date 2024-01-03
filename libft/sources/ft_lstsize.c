/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:07:37 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 16:11:47 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*h;

	i = 0;
	h = lst;
	if (h)
		i++;
	while (h->next != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}
