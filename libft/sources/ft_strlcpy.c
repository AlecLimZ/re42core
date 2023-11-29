/*******************************************************

* Program : ft_strlcpy.c

* Creation Date : Wed Nov 29 12:08:54 2023

* Author : Alec Lim

* Last Modified : Wed Nov 29 12:30:51 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    int len;

    len = ft_strlen(src);
    if (size <= 0 || !dst || !src)
        return (0);
    while (--size && *src)
        *dst++ = *src++;
    *dst = '\0';
    return (len);
}
