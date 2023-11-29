/*******************************************************

* Program : ft_memmove.c

* Creation Date : Wed Nov 29 09:56:18 2023

* Author : Alec Lim

* Last Modified : Wed Nov 29 12:08:50 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    long        range;
    char        *d;
    const char  *s;
    long        nn;

    d = dest;
    s = src;
    nn = n;
    range = d - s;
    if (range < 0)
        range = -range;
    if (range >= nn)
    {
        while (nn--)
            *d++ = *s++;
        return (d);
    }
    d += n;
    s += n;
    while (nn--)
        *(--d) = *(--s);
    return (d);
}
