#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

void	ft_putnbr(long long n, t_list *node, int *i)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -1 * n;
	}
	if ((node->prec = node->prec - *i) > 0)
		while (--node->prec > -1)
		{
			write(1, "0", 1);
			*i = *i + 1;
		}
	if (n >= 0 && n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, node, i);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

int		ft_get_length(long long value)
{
	int i;

	i = 0;
	if (value < 0)
	{
		if (value == -2147483648)
			value = value + 1;
		value = -1 * value;
		i++;
	}
	if (value == 0)
		return (1);
	while (value)
	{
		value = value / 10;
		i++;
	}
	return (i);
}

int		ft_itoa_x(unsigned long long value, char type, int flag, t_list *nd)
{
	char	*sb;
	char	*str;
	int		n;
	int		g;

	g = 0;
	n = ft_get_length((long long)value);
	sb = "0123456789ABCDEF";
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (-1);
	if (type == 'x')
		sb = "0123456789abcdef";
	str[n] = '\0';
	if (value == 0 && (n = n - 1) == 0)
		str[n] = '0';
	while (value && --n >= 0)
	{
		str[n] = sb[value % 16];
		value = value / 16;
	}
	if (flag)
		g = ft_write(nd, n, str, g);
	free(str);
	return ((int)ft_strlen(str + n) + g);
}

int		ft_itoa_p(unsigned long long value, int flag)
{
	char	*sb;
	int		n;
	char	*str;

	if (flag)
		write(1, "0x", 2);
	sb = "0123456789abcdef";
	n = ft_get_length((long long)value);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (-1);
	str[n] = '\0';
	if (value == 0 && (n = n - 1) == 0)
		str[n] = '0';
	while (value)
	{
		n--;
		str[n] = sb[value % 16];
		value = value / 16;
	}
	if (flag)
		write(1, str + n, ft_strlen(str + n));
	free(str);
	n = ft_strlen(str + n);
	return (n);
}
