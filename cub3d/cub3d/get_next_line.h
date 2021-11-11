#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "tools.h"

int		get_next_line(int fd, char **line);
char	*ft_strjoin_my(char **s1, char *s2);
char	*ft_strcopy(char *dst, char *src, int ind, int len);

#endif
