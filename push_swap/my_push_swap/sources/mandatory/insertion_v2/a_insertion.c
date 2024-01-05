/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_insertion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:37 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:32:28 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool is_insertion_index(int a_index, int b_int, int a_last)
{
	int	a_int;

	a_int = get_a_int_by_index(a_index);
	if (a_int < b_int)
		return (false);
	if (a_index == 0)
		if (a_last > b_int)
			return (false);
	if (a_index > 0)
		if (get_a_int_by_index(a_index - 1) > b_int)
			return (false);
	return (true);
}

int	find_a_insertion_index(int b_int)
{
	int	a_index;
	int	a_last;

	a_index = 0;
	a_last = last_int_of_a();
	while (true)
	{
		if (is_insertion_index(a_index, b_int, a_last))
			break ;
		a_index++;
		continue ;
	}
	return (a_index);
}
