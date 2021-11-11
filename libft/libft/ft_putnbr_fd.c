#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	c = '0';
	if (fd != -1)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		if (n < 0 && n != -2147483648)
		{
			write(fd, "-", 1);
			n = -1 * n;
		}
		if (n >= 0 && n < 10)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			c = n % 10 + 48;
			write(fd, &c, 1);
		}
	}
}
