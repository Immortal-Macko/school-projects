/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 01:57:51 by flouie            #+#    #+#             */
/*   Updated: 2021/01/18 22:44:33 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_strcopy(char *dst, char *src, int ind, int len);

#endif
