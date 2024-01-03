/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:48:12 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:59:19 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long		i;
	long		nn;
	const char	*s2;
	char		*s1;

	i = -1;
	nn = n;
	s1 = (char *)dest;
	s2 = (const char *)src;
	while (++i < nn)
		s1[i] = s2[i];
	return (s1);
}
