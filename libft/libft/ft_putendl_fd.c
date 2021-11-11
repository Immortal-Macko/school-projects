#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t len;

	if (s != NULL)
		len = ft_strlen((const char *)s);
	if (s != NULL && fd > -1)
	{
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}
