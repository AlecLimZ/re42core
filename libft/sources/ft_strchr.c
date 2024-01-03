/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:51:17 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:51:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(s);
	if (!s || c < 0)
		return (NULL);
	while (++i <= len)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
