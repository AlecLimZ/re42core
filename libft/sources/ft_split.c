/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:28:11 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 15:26:32 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s++ == c)
			break ;
		i++;
	}
	return (i);
}

int	ft_arraylen(char const *s, char delimit, int *pp, int *ii)
{
	int	i;
	int	p;

	i = 0;
	p = -1;
	*pp = 0;
	*ii = 0;
	if (!s)
		return (0);
	while (s[++p])
		if (s[p] == delimit && s[p + 1] != '\0')
			i++;
	if (s[0] == delimit)
	{
		i--;
		*pp += 1;
	}
	return (i + 1);
}

static int	ft_assign(char **split, int i, int len)
{
	split[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!split[i])
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		alen;
	int		p;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	alen = ft_arraylen(s, c, &p, &i);
	split = (char **)malloc(sizeof(char *) * (alen + 1));
	if (!split)
		return (NULL);
	while (--alen + 1)
	{
		len = ft_countlen(s + p, c);
		if (!ft_assign(split, i, len))
			return (NULL);
		ft_memcpy(split[i], s + p, len);
		split[i++][len] = '\0';
		p += len + 1;
	}
	split[i] = NULL;
	return (split);
}
