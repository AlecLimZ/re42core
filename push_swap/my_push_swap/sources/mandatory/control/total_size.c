/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:04:13 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:05:11 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	total_size(void)
{
	return (get_total_size());
}

int get_total_size(void)
{
	return (c()->total_size);
}

void	set_total_size(void)
{
	c()->total_size = ft_dlstsize(*a());
}
