/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:26:23 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/02 20:26:28 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
