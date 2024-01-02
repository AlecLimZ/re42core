#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*cs1;
	const char	*cs2;

	i = -1;
	cs1 = (const char *)s1;
	cs2 = (const char *)s2;
	while (++i < n)
	{
		if (cs1[i] != cs2[i])
		{
			if ((unsigned char)cs1[i] - (unsigned char)cs2[i] > 0)
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
