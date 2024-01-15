/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:50:06 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 13:03:54 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		init_line_low(t_vec2i *line, t_vec2i start, t_vec2i end, int *yi)
{
	line->x = end.x - start.x;
	line->y = end.y - start.y;
	*yi = 1;
	if (line->y < 0)
	{
		*yi = -1;
		line->y = -line->y;
	}
}

void		print_line_low(t_vec2i start, t_vec2i end, t_img *img)
{
	int		yi;
	int		max;
	t_vec2i	line;
	t_vec2i	coord;

	coord.x = start.x;
	init_line_low(&line, start, end, &yi);
	max = (2 * line.y) - line.x;
	coord.y = start.y;
	while (coord.x < end.x)
	{
		write_pixel(img, coord.x, coord.y, RED);
		if (max > 0)
		{
			coord.y = coord.y + yi;
			max = max + (2 * (line.y - line.x));
		}
		else
			max = max + (2 * line.y);
		coord.x++;
	}
}

void		init_line_high(t_vec2i *line, t_vec2i start, t_vec2i end, int *xi)
{
	line->x = end.x - start.x;
	line->y = end.y - start.y;
	*xi = 1;
	if (line->x < 0)
	{
		*xi = -1;
		line->x = -line->x;
	}
}

void		print_line_high(t_vec2i start, t_vec2i end, t_img *img)
{
	int		xi;
	int		max;
	t_vec2i line;
	t_vec2i coord;

	coord.x = start.x;
	init_line_high(&line, start, end, &xi);
	max = 2 * line.x - line.y;
	coord.y = start.y;
	while (coord.y < end.y)
	{
		write_pixel(img, coord.x, coord.y, RED);
		if (max > 0)
		{
			coord.x = coord.x + xi;
			max = max + (2 * (line.x - line.y));
		}
		else
			max = max + (2 * line.x);
		coord.y++;
	}
}

void		print_line(t_vec2i start, t_vec2i end, t_img *img)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			print_line_low(end, start, img);
		else
			print_line_low(start, end, img);
	}
	else
	{
		if (start.y > end.y)
			print_line_high(end, start, img);
		else
			print_line_high(start, end, img);
	}
}
