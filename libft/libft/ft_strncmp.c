#include "libft.h"

static int	ft_check(unsigned char *str1, unsigned char *str2, size_t i)
{
	if (str1[i] > str2[i])
		return (1);
	if (str1[i] == str2[i])
		return (0);
	else
		return (-1);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
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
		if (str1[i] > str2[i])
			return (1);
		else
			return (-1);
	}
	else
		return (ft_check(str1, str2, i));
}
