#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(s);
	if (!s || c < 0)
		return (NULL);
	while (++i <= len)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
