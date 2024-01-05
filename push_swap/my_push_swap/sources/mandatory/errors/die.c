/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:58:25 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 14:59:21 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	die(void)
{
	free_memory();
	ft_putstr_fd(ERR_GENERIC, SRDERR_FILENO);
	exit(EXIT_FAILURE);
}
