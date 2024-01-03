/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:25:37 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 15:01:08 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!dst || !src || size <= 0)
		return (0);
	len = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) > size)
		return (0);
	i = ft_strlen(dst);
	while (i < (size - 1) && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (len);
}
