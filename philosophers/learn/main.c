/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:39:32 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/11 16:53:23 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*my_turn(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("You're a cutie! %d\n", i);
	}
	return (NULL);
}

void	*your_turn()
{
	for (int i = 0; i < 2; i++)
	{
		sleep(2);
		printf("No! You are!\n");
	}
	return (NULL);
}

int main()
{
	int			status;
	pthread_t	newthread;

	pthread_create(&newthread, NULL, my_turn, NULL);
	your_turn();
	pthread_join(newthread, NULL);
	return (0);
}
