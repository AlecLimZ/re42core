/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:51:24 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:51:25 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	if (!s1)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	return (new);
}
