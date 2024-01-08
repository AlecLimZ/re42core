/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:22:39 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/05 18:27:29 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	g_t;
int	bi_conv(int pos)
{
	int	base;
	int	ret;

	if (!pos)
		return (1);
	base = 2;
	ret = 2;
	while (pos > 1)
	{
		ret	*= base;
		pos--;
	}
	return (ret);
}

void	handle(int sig, siginfo_t *data, void *empty)
{
	static int	pos = 7;
	static int	sum = 0;

	(void)empty;
	if (g_t != data->si_pid)
	{
		sum = 0;
		pos = 7;
	}
	if (sig == SIGUSR1)
	{
		sum += bi_conv(pos);
		pos--;
	}
	else
		pos--;
	if (pos == -1)
	{
		write(1, &sum, 1);
		pos = 7;
		sum = 0;
	}
	g_t = data->si_pid;
}

int	main(void)
{
	pid_t				procces;
	int					i;
	struct sigaction	sig;

	write(1, "Server PID: ", 12);
	procces = getpid();
	ft_putnbr_fd(procces, 1);
	write(1, "\n", 1);
	sig.sa_sigaction = &handle;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	i = 0;
	while (1)
	{
		if (i != g_t)
		{
			i = g_t;
			kill(g_t, SIGUSR2);
		}
		pause();
	}
	return (0);
}
