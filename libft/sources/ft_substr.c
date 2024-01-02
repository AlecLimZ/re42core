#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!sub)
		return (NULL);
	while (start < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
