/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:25:50 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 13:58:50 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <defines.h>
# include <libft.h>

typedef struct s_push_swap
{
	bool	verbose;

	int		argc;
	char	**argv;

	int		new_int;
	int		total_size;

	t_dlist	*a;
	t_dlist	*b;

	t_list	*lalloc;
			t_push_swap;
}

typedef void	(*t_operation_cb)(void);

/******************************************************************************\
  * CONTROL
\******************************************************************************/
t_pyush_swap	*c(void);
void			initialize_control(int argc, char **argv);

bool			verbose(void);
void			set_verbose(bool verbose);

int				argc(void);
char			**argv(void);

int				total_size(void);
int				get_total_size(void);
void			set_total_size(void);

t_dlist			**a(void);
t_dlist			**b(void);

t_list			**lalloc(void);
void			free_memory(void);

/******************************************************************************\
  * ARGUMENTS
\******************************************************************************/

void			handle_arguments(void);

void			validate_argc(void);

void			parse_argv(void);
void			number_or_die(char *str);
int				int_or_die(char *str);

/******************************************************************************\
 * OPERATIONS
\******************************************************************************/

void		sa(void);
void		sb(void);
void		ss(void);

void		pa(void);
void		pb(void);

void		ra(void);
void		rb(void);
void		rr(void);

void		rra(void);
void		rrb(void);
void		rrr(void);

void		execute(char *operation);
void		execute_n_times(char *operation, int n);

/******************************************************************************\
 * STACKS
\******************************************************************************/

void	inspect_stacks(void);
void	put_sort_status(void);

t_dlist	*clone_stack(t_dlist **original);

bool	is_sorted(void);
void	validate_sort(void);

void	set_int(t_dlist *node, int number);
int		get_int(t_dlist *node);
int		get_next_int(t_dlist *node);

void	normalize_a(void);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void		log_state(void);
void		log_normalized(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
