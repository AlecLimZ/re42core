/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:25:47 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:56:24 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		nlen;

	i = -1;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (++i < len && haystack && haystack[i])
		if (ft_strncmp(haystack + i, needle, nlen) == 0)
			return ((char *)haystack + i);
	return (NULL);
}
