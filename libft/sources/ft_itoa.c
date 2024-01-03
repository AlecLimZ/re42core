/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:10:12 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/03 14:46:19 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;
	int		m;

	m = 0;
	if (n < 0)
	{
		m = 1;
		n *= -1;
	}
	len = ft_numlen(n) + m;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (n)
	{
		new[--len] = '0' + (n % 10);
		n /= 10;
	}
	if (m)
		new[--len] = '-';
	return (new);
}
