/*******************************************************

* Program : ft_isalnum.c

* Creation Date : Tue Nov 28 11:01:46 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 11:24:22 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

int	ft_isalnum(const char c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (8);
	return (0);
}
