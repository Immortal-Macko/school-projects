#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	len;

	len = ft_strlen(s);
	c1 = (char)c;
	while (len)
	{
		if (s[len] == c1)
			return ((char *)(s + len));
		len--;
	}
	if (s[len] == c1)
		return ((char *)(s + len));
	return (NULL);
}
