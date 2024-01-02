/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:25:07 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/02 20:25:15 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
