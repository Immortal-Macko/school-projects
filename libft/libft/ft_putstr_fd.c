/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:16:50 by flouie            #+#    #+#             */
/*   Updated: 2020/11/21 21:40:42 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
