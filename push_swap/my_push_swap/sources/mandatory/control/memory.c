/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:02:25 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:03:09 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	**lalloc(void)
{
	return (&(c()->lalloc));
}

void	free_memory(void)
{
	ft_free_lalloc(&(c()->lalloc));
}
