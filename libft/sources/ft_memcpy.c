/*******************************************************

* Program : ft_memcpy.c

* Creation Date : Tue Nov 28 13:53:41 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 18:01:39 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    long        i;
    long        nn;
    const char  *s2;
    char        *s1;

    i = -1;
    nn = n;
    s1 = (char *)dest;
    s2 = (const char*)src;
    while (++i < nn)
        s1[i] = s2[i];
    return (s1);
}
