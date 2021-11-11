/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:30:22 by flouie            #+#    #+#             */
/*   Updated: 2020/11/19 19:15:21 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	len;

	len = ft_strlen(s);
	c1 = (char)c;
	while (len)
	{
		if (s[len] == c1)
			return ((char *)(s + len));
		len--;
	}
	if (s[len] == c1)
		return ((char *)(s + len));
	return (NULL);
}
