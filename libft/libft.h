#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

extern size_t	ft_strlen(const char *string) __attribute__((nonnull));
extern int		ft_isalpha(int letter);
extern int		ft_isdigit(int letter);
extern int      ft_isalnum(const char c);
extern int      ft_isascii(int letter);
extern int      ft_isprint(const char c);
extern void     *ft_memset(void *s, int c, size_t n);
extern void     ft_bzero(void *s, size_t n);
extern void     *ft_memcpy(void *dest, const void *src, size_t n) __attribute__((nonnull));
extern void     *ft_memmove(void *dest, const void *src, size_t n);
extern size_t   ft_strlcpy(char *dst, const char *src, size_t size);
extern size_t   ft_strlcat(char *dst, const char *src, size_t size);
extern int		ft_toupper(int c);
extern int		ft_tolower(int c);
extern char		*ft_strchr(char const *s, int c);
extern char		*ft_strrchr(char const *s, int c);

#endif
