/*******************************************************

* Program : ft_strlcat.c

* Creation Date : Wed Nov 29 12:30:56 2023

* Author : Alec Lim

* Last Modified : Wed Nov 29 14:00:42 2023

* Created By : Alec Lim

*******************************************************/

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  len;
    size_t  i;

    if (!dst || !src || size <= 0)
        return (0);
    len = ft_strlen(dst) + ft_strlen(src);
    if (ft_strlen(dst) > size)
        return (0);
    i = ft_strlen(dst);
    while (i < (size - 1) && *src)
        dst[i++] = *src++;
    dst[i] = '\0';
    return (len);
}
