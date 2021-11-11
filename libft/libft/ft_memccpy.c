#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	d1 = (unsigned char*)dest;
	s1 = (unsigned char*)src;
	c1 = (unsigned char)c;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		if (s1[i] == c1)
		{
			d1[i] = c1;
			return (&d1[i + 1]);
		}
		d1[i] = s1[i];
		i++;
	}
	return (NULL);
}
