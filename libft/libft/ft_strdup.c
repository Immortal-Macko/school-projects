/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:48:56 by flouie            #+#    #+#             */
/*   Updated: 2020/11/20 19:17:56 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy_local(char *dest, const char *src)
{
	size_t n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

static int		ft_strcmp_local(const char *s1, char *s2)
{
	size_t n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] != '\0' && s2[n] != '\0')
	{
		n++;
	}
	if (s1[n] == '\0' && s2[n] == '\0')
		return (0);
	else
	{
		if (s1[n] > s2[n])
			return (1);
		else
			return (-1);
	}
}

static size_t	ft_strlen_local(const char *str)
{
	size_t n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	n++;
	return (n);
}

char			*ft_strdup(const char *s)
{
	char			*str2;
	size_t			len;

	len = ft_strlen_local(s);
	str2 = (char*)malloc(sizeof(*s) * len);
	if (str2 == NULL)
		return (NULL);
	str2 = ft_strcpy_local(str2, s);
	if (ft_strcmp_local(s, str2) == 0)
		return (str2);
	else
		return (NULL);
}
