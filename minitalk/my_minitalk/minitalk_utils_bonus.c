/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:15 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 18:35:44 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_str_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		++i;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int long	nbr;

	nbr = (int long) n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (n / 10)
		ft_putnbr_fd(nbr /10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int	ft_atoi(const char *str)
{
	int	j;
	int	res;

	j = 1;
	res = 0;
	while (*str == '\t' || *str == '\f' || *str == '\r'
			|| *str == ' ' || *str == '\v' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * j);
}
