/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:54:19 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/04 13:59:59 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_pr(t_data *tab)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	tab->tl += 1;
}

void	ft_print_spaces(int nb)
{
	int		i;
	char	b;

	b = ' ';
	i = 0;
	while (i < nb)
	{
		write(1, &b, 1);
		i++;
	}
}

char	*ft_fuck_this_stupid_rule(t_data *tab, char *anew,  char *a)
{
	int	i;
	int	j;

	if (tab->plus)
		anew[0] = '+';
	else if (tab->space)
		anew[0] = ' ';
	i = 1;
	j = 0;
	while (a[j])
		anew[i++] = a[j++];
	anew[i] = '\0';
	return (anew);
}

char	*ft_add_ps(t_data *tab, char *a)
{
	char	*anew;

	anew = (char *)malloc(sizeof(char) * ft_strlen(a) + 2);
	if (!anew)
		return (NULL);
	anew = ft_fuck_this_stupid_rule(tab, anew, a);
	free(a);
	return (anew);
}

char	*ft_print_null(char *a)
{
	char	*anew;

	anew = (char *)malloc(sizeof(char) * 7);
	if (!anew)
		return (NULL);
	anew[0] = '(';
	anew[1] = 'n';
	anew[2] = 'u';
	anew[3] = 'l';
	anew[4] = 'l';
	anew[5] = ')';
	anew[6] = '\0';
	free(a);
	return (anew);
}
