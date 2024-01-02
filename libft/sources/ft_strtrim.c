/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:24:23 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/02 20:24:25 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		t;
	int		s;

	if (!s1 || !set)
		return (NULL);
	trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!trim)
		return (NULL);
	i = -1;
	t = 0;
	while (s1[++i])
	{
		j = -1;
		s = 0;
		while (set[++j])
			if (s1[i] == set[j])
				s = 1;
		if (!s)
			trim[t++] = s1[i];
	}
	trim[t] = '\0';
	return (trim);
}
