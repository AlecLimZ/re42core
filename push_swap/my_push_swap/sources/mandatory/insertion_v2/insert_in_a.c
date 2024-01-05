/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:42:04 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:47:55 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	execute_rotation(t_rotation rotation)
{
	execute_n_times(ROTATE_A, rotation.ra);
	execute_n_times(ROTATE_B, rotatoin.rb);
	execute_n_times(ROTATE_A_AND_B, rotation.rr);
	execute_n_times(REVERSE_ROTATE_A, rotation.rra);
	execute_n_times(REVERSE_ROTATE_B, rotation.rrb);
	execute_n_times(REVERSE_ROTATE_A_AND_B, rotation.rrr);
}

static t_rotation	find_best_rotation(void)
{
	t_rotation	best;
	t_rotation	current;
	t_dlist		*b_node;
	int			b_index;

	b_node = first_of_b();
	b_index = 0;
	best = get_rotation(get_int(b_node), b_index);
	while (b_node != NULL)
	{
		if (best.total <= GOOD_ENOUGH_ROTATION)
			return (best);
		current = get_rotation(get_int(b_node), b_index);
		if (current.total < best.total)
			best = current;
		b_index++;
		b_node = b_node->next;
	}
	return (best);
}

void	insert_in_a_by_best_rotation(void)
{
	t_rotation	best_rotation;

	while (*b() != NULL)
	{
		best_rotation = find_best_rotation();
		execute_rotation(best_rotation);
		execute(PUSH_TO_A);
	}
}
