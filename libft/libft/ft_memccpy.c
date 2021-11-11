/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:26:45 by flouie            #+#    #+#             */
/*   Updated: 2020/11/20 19:16:21 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	d1 = (unsigned char*)dest;
	s1 = (unsigned char*)src;
	c1 = (unsigned char)c;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		if (s1[i] == c1)
		{
			d1[i] = c1;
			return (&d1[i + 1]);
		}
		d1[i] = s1[i];
		i++;
	}
	return (NULL);
}
