/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_timer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:07 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/12 12:11:00 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TIMER_H
# define CUB_TIMER_H

typedef struct		s_timer
{
	unsigned long	ref_time;
	unsigned long	elapsed_time;
	bool			pause;
}					t_timer;

typedef	struct		s_frame
{
	int				fps;
	int				lastfps;
	t_timer			timer;
}					t_frame;

unsigned long		get_time(void);
void				timer_restart(t_timer *timer);
unsigned long		timer_get_microseconds(t_timer *timer);
unsigned long		timer_get_milliseconds(t_timer *timer);
double				timer_get_seconds(t_timer *timer);

#endif
