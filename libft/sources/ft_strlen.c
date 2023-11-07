/*******************************************************

* Program : ft_strlen.c

* Creation Date : Fri Nov  3 13:38:13 2023

* Author : Alec Lim

* Last Modified : Fri Nov  3 14:02:10 2023

* Created By : Alec Lim

*******************************************************/

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i]);
	return (i);
}
