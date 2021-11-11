/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:32:57 by flouie            #+#    #+#             */
/*   Updated: 2020/11/22 18:34:06 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_local(const char *s)
{
	size_t n;

	n = 0;
	if (s == NULL)
		return (0);
	else
	{
		while (s[n] != '\0')
		{
			n++;
		}
	}
	return (n);
}

static char		*ft_check(char const *s, size_t len)
{
	char *subs;

	if (s == NULL)
	{
		subs = NULL;
		return (subs);
	}
	subs = (char *)malloc(sizeof(char) * (len + 1));
	return (subs);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	n;
	size_t			slen;

	n = 0;
	slen = ft_strlen_local(s);
	subs = ft_check(s, len);
	if (subs == NULL)
		return (subs);
	if (slen <= start || len == 0)
	{
		subs[0] = '\0';
		return (subs);
	}
	while (len > 0)
	{
		if (s[start] == '\0')
			break ;
		subs[n] = s[start];
		n++;
		start++;
		len--;
	}
	subs[n] = '\0';
	return (subs);
}
