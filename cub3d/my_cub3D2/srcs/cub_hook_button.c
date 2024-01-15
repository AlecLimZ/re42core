/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:49:07 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 19:54:46 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		button_press(int keycode, int x, int y, t_keys *events)
{
	(void)x;
	(void)y;
	if (keycode >= 0 && keycode < BUTTON_MAX)
		events->button_internal[keycode] = true;
	return (0);
}

int		button_release(int keycode, int x, int y, t_keys *events)
{
	(void)x;
	(void)y;
	if (keycode >= 0 && keycode < BUTTON_MAX)
		events->button_internal[keycode] = false;
	return (0);
}

bool	get_button(int keycode, int x, int y, t_keys *events)
{
	(void)x;
	(void)y;
	if (keycode > 0 && keycode < BUTTON_MAX)
		return (events->button[keycode]);
	return (false);
}

bool	get_button_press(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < BUTTON_MAX)
	{
		return (events->button[keycode] &&
		events->last_button[keycode] == false);
	}
	return (false);
}

bool	get_button_release(int keycode, t_keys *events)
{
	if (keycode >= 0 && keycode < BUTTON_MAX)
	{
		return (events->button[keycode] == false &&
		events->last_button[keycode]);
	}
	return (false);
}
