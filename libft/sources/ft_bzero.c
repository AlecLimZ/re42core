/*******************************************************

* Program : ft_bzero.c

* Creation Date : Tue Nov 28 12:33:07 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 13:53:33 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

void   ft_bzero(void *s, size_t n)
{
    char    *c;
    long    i;
    long    nn;

    c = (char*)s;
    i = -1;
    nn = n;
    while (++i < nn)
        c[i] = 0;
}
