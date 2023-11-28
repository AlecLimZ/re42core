/*******************************************************

* Program : ft_memset.c

* Creation Date : Tue Nov 28 12:19:55 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 13:50:36 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    long    i;
    long    chk;
    char    *sc;

    i = -1;
    chk = n;
    sc = (char *)s;
    while (++i < chk)
        sc[i] = c;
    return (s);
}
