#include "libft.h"

static size_t	ft_count_elems(int value)
{
	size_t i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		if (value == -2147483648)
			value = value + 1;
		value = -1 * value;
		i++;
	}
	if (value > 0)
	{
		while (value)
		{
			value = value / 10;
			i++;
		}
	}
	return (i);
}

static char		*ft_fill_str(char *str, size_t len, int value, int count)
{
	int i;

	i = 0;
	if (value < 0)
	{
		str[0] = '-';
		if (value == -2147483648)
		{
			str[1] = '2';
			value = -147483648;
			count++;
		}
		value = -1 * value;
		count++;
	}
	i = len - 1;
	while (i > count)
	{
		str[i] = value % 10 + 48;
		i--;
		value = value / 10;
	}
	str[len] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		count;

	count = -1;
	len = ft_count_elems(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
		str = ft_fill_str(str, len, n, count);
	return (str);
}
