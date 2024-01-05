/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:55:54 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 14:57:53 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	number_or_die(char *str)
{
	if (ft_strlen(str) > INT_MAX_LENGTH)
		die();
	if (ft_is_plus_or_minus(*str))
		str++;
	if (!ft_isdigit(*str))
		die();
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		die();
}

int	int_or_die(char *str)
{
	long	number;

	number = ft_atol(str);
	if (number > INT_MAX)
		die();
	if (number < INT_MIN)
		die();
	return ((int)number);
}
