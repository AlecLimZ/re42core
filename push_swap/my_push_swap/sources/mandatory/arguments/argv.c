/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:48:49 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 14:52:39 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_unique(void *number)
{
	int	current;

	current = *(int *)number;
	if (current == c()->new_int)
		die();
}

static void	unique_or_die(void)
{
	ft_dlstiter(*a(), &check_unique);
}

static void	add_to_a(void)
{
	int	*integer_p;

	integer_p = ft_lalloc(lalloc(), sizeof(int));
	*integer_p = c()->new_int;
	ft_dlst_cadd_back_lalloc(lalloc(), a(), integer_p);
}

void	parse_argv(void)
{
	char	**args;

	args = argv() + 1;
	while (*args != NULL)
	{
		number_or_die(*args);
		c()->new_int = int_or_die(*args);
		unique_or_die();
		add_to_a();
		args++;
	}
}
