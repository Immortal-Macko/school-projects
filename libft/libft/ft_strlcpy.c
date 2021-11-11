/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:16:39 by flouie            #+#    #+#             */
/*   Updated: 2020/11/20 19:21:24 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_local(const char *s)
{
	size_t n;

	n = 0;
	if (s != NULL)
	{
		while (s[n] != '\0')
		{
			n++;
		}
	}
	else
		return (n);
	return (n);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t n;

	n = 0;
	if (src == NULL)
		return (0);
	while (size > 1 && src[n] != '\0')
	{
		dst[n] = src[n];
		n++;
		size--;
	}
	if (size == 1 || src[n] == '\0')
		dst[n] = '\0';
	return (ft_strlen_local(src));
}
