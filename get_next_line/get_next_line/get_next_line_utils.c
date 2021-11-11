#include "get_next_line.h"

char		*ft_calloc(size_t num, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	while (i < num * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t		ft_strlen(char *s)
{
	size_t n;

	n = 0;
	if (s == NULL)
		return (0);
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

static char	*ft_concat(char *s1, char *s2, char *str)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	size_t	len;

	if (*s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	len = ft_strlen(*s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = ft_concat(*s1, s2, str);
	free(*s1);
	return (str);
}

char		*ft_strcopy(char *dst, char *src, int ind, int len)
{
	int i;
	int dlen;

	i = -1;
	if (ind)
		while (src[++i] != '\0')
			dst[i] = src[i];
	else
	{
		while (src[++i] != '\0')
			;
		dlen = len - i - 1;
		i = dlen;
		while (dlen >= 0)
		{
			dst[dlen] = src[len];
			dlen--;
			len--;
		}
	}
	i = i - 1;
	while (++i <= BUFFER_SIZE)
		dst[i] = '\0';
	return (dst);
}
