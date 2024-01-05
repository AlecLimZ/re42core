/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:16:56 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/04 13:19:05 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char *s, int start, int len, int p_null)
{
	char	*sub;
	int		i;

	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	if (p_null)
		free(s);
	sub[i] = '\0';
	return (sub);
}
