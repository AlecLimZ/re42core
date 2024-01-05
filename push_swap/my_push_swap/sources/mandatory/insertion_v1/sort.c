/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:52 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 15:27:38 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_first_two_pushes(int inserted_index)
{
	rotate_to_top_of_a(inserted_index);
	execute(PUSH_TO_B);
}

static void	push_chunk_to_b(int cycles, int chunk)
{
	int	chunk_start;
	int	chunk_end;
	int	inserted_index;
	int	insertion_index;

	chunk_start = cycles * (chunk - 1);
	chunk_end = chunk_start + cycles - 1;
	while (cycles > 0 && first_of_a() != NULL)
	{
		inserted_index = get_a_inserted_index(chunk_start, chunk_end);
		if (ft_dlst_index_out_of_bounds(a(), inserted_index))
			return ;
		if (count_b() < 2)
		{
			handle_first_two_pushes(inserted_index);
			cycles--;
			continue ;
		}
		insertion_index = get_b_insertion_index(inserted_index);
		rotate_to_top_of_stacks(inserted_index, insertion_index);
		execute(PUSH_TO_B);
		cycles--;
	}
}

static void push_chunks_to_b(int chunk_size)
{
	int	chunks;

	chunks = (get_total_size() / chunk_size) + 1;
	while (chunks > 0)
	{
		push_chunk_to_b(chunk_size, chunks);
		chunks--;
	}
}

void	insertion_sort_v1(int chunk_size)
{
	push_chunks_to_b(chunk_size);
	push_all_to_a_sorted();
}
