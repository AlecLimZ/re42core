/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:32:53 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:37:11 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	calculate_all_rotations(t_rotation *rotations, int b_int, int b_index)
{
	int	a_index;

	ft_bzero(rotations, sizeof(t_rotation) * 4);
	a_index = find_a_insertion_index(b_int);
	set_up_up_rotation(rotations, b_index, a_index);
	set_down_down_rotation(rotations, b_index, a_index);
	set_up_down_rotation(rotations, b_index, a_index);
	set_down_up_rotation(rotations, b_index, a_index);
}

t_rotation	get_rotation(int b_int, int b_index)
{
	t_rotation	rotations[4];
	t_direction	current;
	t_direction	best;

	calculate_all_rotations(rotations, b_int, b_index);
	best = FIRST;
	current = SECOND;
	while (current <= LAST)
	{
		if (rotations[current].total < rotations[best].total)
			best = current;
		current++;
	}
	return (rotations[best]);
}
