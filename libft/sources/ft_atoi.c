/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:24:29 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:43:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	p;
	int	s;
	int	t;

	p = 0;
	s = 1;
	t = 0;
	if (!str)
		return (0);
	while (str[p] && ft_isspace(str[p]))
		p++;
	if (str[p] == '-' || str[p] == '+')
		if (str[p++] == '-')
			s = -1;
	if (!ft_isdigit(str[p]))
		return (0);
	while (str[p] && ft_isdigit(str[p]))
		t = t * 10 + (str[p++] - '0');
	return (t * s);
}
