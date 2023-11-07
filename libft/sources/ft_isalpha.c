/*******************************************************

* Program : ft_isalpha.c

* Creation Date : Fri Nov  3 14:23:55 2023

* Author : Alec Lim

* Last Modified : Fri Nov  3 15:12:10 2023

* Created By : Alec Lim

*******************************************************/

int ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1024 : 0);
}
