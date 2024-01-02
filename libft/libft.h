#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern void		*ft_memchr(const void *s, int c, size_t n);
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
extern int		ft_atoi(const char *str);
extern int		ft_isspace(int c);
extern void		*ft_calloc(size_t count, size_t size);
extern char		*ft_strdup(const char *s1);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern char		*ft_strtrim(char const *s1, char const *set);
extern char		**ft_split(char const *s, char c);
extern char		*ft_itoa(int n);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern void		ft_striteri(char *s, void (*f)(unsigned int, char *));
#endif
