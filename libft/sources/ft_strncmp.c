/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:55:44 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:55:46 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n && s1 && s2 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] - s2[i] > 0)
				return (1);
			else
				return (-1);
		}
	}
	return (s1[i] - s2[i]);
}
