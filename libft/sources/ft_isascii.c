/*******************************************************

* Program : ft_isascii.c

* Creation Date : Tue Nov 28 11:31:41 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 12:17:57 2023

* Created By : Alec Lim

*******************************************************/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
