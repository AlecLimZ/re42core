/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:44:12 by jungwkim          #+#    #+#             */
/*   Updated: 2021/03/31 12:35:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int		validate_sq(char **strs)
{
	t_vec	dir;
	t_vec	rgb;

	if ((ft_strslen(strs)) != 5)
		return (0);
	if (!ft_iscoordinate(strs[1]))
		return (0);
	if (!ft_atov(strs[2], &dir))
		return (0);
	if (!ft_isrange(dir.x, -1, 1)
			|| !ft_isrange(dir.y, -1, 1)
			|| !ft_isrange(dir.z, -1, 1))
		return (0);
	if (!check_str_to_float(strs[3]))
		return (0);
	if (!ft_atov(strs[4], &rgb))
		return (0);
	if (!ft_isrange(rgb.x, 0, 255)
			|| !ft_isrange(rgb.y, 0, 255)
			|| !ft_isrange(rgb.z, 0, 255))
		return (0);
	return (1);
}
