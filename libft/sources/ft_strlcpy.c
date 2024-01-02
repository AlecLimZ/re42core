/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:26:38 by leng-chu          #+#    #+#             */
/*   Updated: 2024/01/02 20:26:42 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
