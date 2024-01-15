/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:03:08 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/15 16:07:38 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	credits_message(bool *help)
{
	*help = true;
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("Cub3D par Clement Sapt (csapt).\n");
	ft_printf("csapt@student.42lyon.fr\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("Un grand merci a Tryrun pour son aide sur le projet.\n");
	ft_printf("Et merci aussi a tous ceux qui m'ont aide de pres ou de loin a \
reussir ce projet: Agathe, Nicolas, Killian, Terry, Yiching, Elyas, Romain, \
Mael, Salome, Ludo...\n");
}

void	help_message(bool *help)
{
	*help = true;
	ft_putstr_fd(GREEN_DEBUG, 1);
	ft_printf("Cub3D par Clement Sapt (csapt)\n");
	ft_putstr_fd(RESET_ERROR, 1);
	ft_printf("Launch the game with ./Cub3D map.cub\n");
	ft_printf("Then you can add an option:\n");
	ft_printf(" - Use --help for see the commands.\n");
	ft_printf(" - Use --save to make a screenshot of the game.\n");
	ft_printf(" - Use --ignore to ignore warning message.\n");
	ft_printf(" - Use --data to see parsing data.\n");
}
