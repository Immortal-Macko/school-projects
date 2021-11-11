/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:25:12 by flouie            #+#    #+#             */
/*   Updated: 2020/11/21 19:19:49 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
