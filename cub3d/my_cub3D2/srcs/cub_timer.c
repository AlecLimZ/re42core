/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:50 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:51 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned long		get_time(void)
{
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
	return (actual_time.tv_sec * 1000000 + actual_time.tv_usec);
}

void				timer_restart(t_timer *timer)
{
	timer->ref_time = get_time();
	timer->elapsed_time = 0;
	timer->pause = false;
}

unsigned long		timer_get_microseconds(t_timer *timer)
{
	return (get_time() - timer->ref_time);
}

unsigned long		timer_get_milliseconds(t_timer *timer)
{
	return (timer_get_microseconds(timer) / 1000);
}

double				timer_get_seconds(t_timer *timer)
{
	return ((double)timer_get_microseconds(timer) / 1000000);
}
