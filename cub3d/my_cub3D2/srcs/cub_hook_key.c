/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:33:32 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 11:39:41 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->key_internal[keycode] = true;
	return (0);
}

int		key_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		events->key_internal[keycode] = false;
	return (0);
}

bool	get_key_press(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode] && events->last_key[keycode] == false);
	return (false);
}

bool	get_key_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode] == false && events->last_key[keycode]);
	return (false);
}

bool	get_key(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (events->key[keycode]);
	return (false);
}
