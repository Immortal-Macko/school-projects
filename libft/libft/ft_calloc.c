#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *str;

	str = (void *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
