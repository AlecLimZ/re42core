/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:37:04 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/08 18:14:55 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BONUS_H
# define KEY_BONUS_H

# define X_EVENT_KEY_PRESS	2

/* Clicking on the RED cross on the window frame */
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC			53
# define KEY_R				15
# define KEY_RETURN			36

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124

typedef struct s_game	t_game;

int		deal_key(int key_code, t_game *game);

#endif
