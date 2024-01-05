/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:05:33 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:06:13 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	verbose(void)
{
	return (c()->verbose);
}

void	set_verbose(bool verbose)
{
	c()->verbose = verbose;
}
