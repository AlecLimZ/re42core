/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:26:13 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/04 15:27:54 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_data *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->space = tab->width - 1;
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	tab->tl += write(1, &a, 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}
