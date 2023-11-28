/*******************************************************

* Program : ft_isalpha.c

* Creation Date : Fri Nov  3 14:23:55 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 10:30:12 2023

* Created By : Alec Lim

*******************************************************/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}
