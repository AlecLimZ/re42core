/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:13:06 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 18:15:58 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_sendsig(char b_c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(500);
		if (b_c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	handler2(int sig)
{
	(void)sig;
	write(1, "Signal Received", 15);
}

int main(int ac, char *av[])
{
	int	i;
	int	pid;

	if (ac == 3 && ft_str_isnum(av[1]))
	{
		pid = ft_atoi(av[1]);
		i = 0;
		signal(SIGUSR2, &handler2);
		while (av[2][i])
		{
			ft_sendsig(av[2][i], pid);
			i++;
			usleep(200);
		}
	}
	else
	{
		write(1, "./client [server-pid] [message]\n", 33);
		exit(0);
	}
	return (0);
}
