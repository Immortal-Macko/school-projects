#include "tools.h"

int	ft_to_int(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == 4)
			break ;
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		n = 10000;
	return (n);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*str;

	str = (void *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s != NULL)
		len = ft_strlen((const char *)s);
	if (s != NULL && fd > -1)
	{
		write(fd, s, len);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((s1 == NULL && s2 == NULL) || (s1[0] == s2[0] && s1[0] == '\0') \
			|| n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0' && i < n)
		i++;
	if (i > 0)
	{
		if (str1[i - 1] == str2[i - 1] && \
				((str1[i] == '\0' && str2[i] == '\0') || i == n))
			return (0);
		else
			return (-1);
	}
	else
		return (-1);
}
