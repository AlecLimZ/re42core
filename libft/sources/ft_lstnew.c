/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:38 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 15:40:55 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
