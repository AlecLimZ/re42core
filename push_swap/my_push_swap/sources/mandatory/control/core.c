/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:56 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:02:14 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_push_swap *c(void)
{
	static t_push_swap	__control_instance;

	return (&__control_instance);
}

void	initialize_control(int argc, char **argv)
{
	c()->verbose = false;
	c()->argc = argc;
	c()->argv = argv;
}
