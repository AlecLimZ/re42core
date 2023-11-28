/*******************************************************

* Program : ft_strlen.c

* Creation Date : Fri Nov  3 13:38:13 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 11:21:06 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
