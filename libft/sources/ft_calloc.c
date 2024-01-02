#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = malloc(count * size);
	ft_bzero(new, sizeof(new));
	return (new);
}
