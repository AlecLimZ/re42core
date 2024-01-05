/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:23:11 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/04 13:25:58 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int count_length(unsigned long long nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_ulitoa_hex(unsigned long long nb)
{
	char	*str;
	char	*tab;
	int		size;

	size = 0;
	tab = "0123456789abcdef";
	size = count_length(nb);
	if (nb == 0)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(nb % 16)];
		size--;
		nb = nb / 16;
	}
	return (str);
}
