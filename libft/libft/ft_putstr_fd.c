#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	if (s != NULL)
		len = ft_strlen((const char *)s);
	if (s != NULL && fd > -1)
	{
		write(fd, s, len);
	}
}
