/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:18:26 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 13:23:36 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
  * ARGUMENTS
\******************************************************************************/

# define INT_MAX_LENGTH 11

/******************************************************************************\
  * STACKS
\******************************************************************************/

# define A_STACK_LABEL 'a'
# define B_STACK_LABEL 'b'

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_A_AND_B "ss"

# define PUSH_TO_A "pa"
# define PUSH_TO_B "pb"

# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_A_AND_B "rr"

# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"
# define REVERSE_ROTATE_A_AND_B "rrr"

# define NORMALIZE_MESSAGE "NORMALIZED STACK"
# define NORMALIZE_MIN 0

/******************************************************************************\
  * INSERTION SORT V1
\******************************************************************************/

# define INSERTION_CHUNK_SIZE_100 20
# define INSERTION_CHUNK_SIZE_500 30

/******************************************************************************\
  * INSERTION SORT V2
\******************************************************************************/

# define GOOD_ENOUGH_ROTATION 7

/******************************************************************************\
  * ERRORS
\******************************************************************************/

# define ERR_GENERIC "Error\n"

#endif
