/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:31:40 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:04:53 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sort_by_len(t_stack **a, t_stack **b, int len)
{
	if (len == 3)
		sort_3(a, b);
	else if (len == 4 || len == 5)
		sort_4_or_5(a, b);
	else
		a_to_b(a, b, len);
}

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->val == get_min_val(*a))
	{
		do_op("sa", a, b);
		do_op("ra", a, b);
	}
	else if ((*a)->val == get_max_val(*a))
		do_op("ra", a, b);
	else
	{
		if ((*a)->nxt->val == get_min_val(*a))
			do_op("sa", a, b);
		else
			do_op("rra", a, b);
	}
}

void	sort_4_or_5(t_stack **a, t_stack **b)
{
	int	min_val;
	int	max_val;
	int	cnt_pb;

	min_val = get_min_val(*a);
	max_val = get_max_val(*a);
	cnt_pb = 0;
	while (get_stack_size(*a) > 3)
	{
		if ((*a)->val == min_val || (*a)->val == max_val)
		{
			do_op("pb", a, b);
			++cnt_pb;
		}
		else
			do_op("ra", a, b);
	}
	if (is_dscnd(*a, 3))
		reverse_stack_a(a, b, 3);
	else if (!is_ascnd(*a, 3))
		sort_3(a, b);
	while (cnt_pb-- > 0)
		sort_minmax(a, b, min_val);
}

void	sort_minmax(t_stack **a, t_stack **b, int min_val)
{
	if ((*b)->val == min_val)
		do_op("pa", a, b);
	else
	{
		do_op("pa", a, b);
		do_op("ra", a, b);
	}
}
