/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:39:16 by flouie            #+#    #+#             */
/*   Updated: 2020/11/21 20:54:20 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_concat(char *dst, const char *src, size_t size, size_t d)
{
	size_t i;
	size_t d1;

	d1 = d;
	i = 0;
	size = size - d;
	while (size > 1)
	{
		if (src[i] == '\0')
			break ;
		dst[d1] = src[i];
		d1++;
		i++;
		size--;
	}
	if (src[i] == '\0' || size == 1)
		dst[d1] = '\0';
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s;
	size_t d;

	s = ft_strlen(src);
	d = ft_strlen((const char *)dst);
	if ((int)size - 1 < (int)d)
		return (size + s);
	else
	{
		ft_concat(dst, src, size, d);
		return (s + d);
	}
}
