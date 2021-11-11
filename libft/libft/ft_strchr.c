#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c1;

	i = 0;
	c1 = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i++;
	}
	if (c1 == '\0' && s[i] == '\0')
		return ((char *)(s + i));
	return (NULL);
}
