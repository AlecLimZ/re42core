/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:26:17 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/02 20:26:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*cs;
	unsigned char	uc;

	i = -1;
	uc = c;
	cs = (const char *)s;
	while (++i < n && cs && cs[i])
		if (cs[i] == uc)
			return ((void *)cs + i);
	return (NULL);
}
