/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:50:34 by flouie            #+#    #+#             */
/*   Updated: 2020/11/23 10:29:54 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_check(size_t i, const char *s, const char *s1, size_t len)
{
	size_t n;
	size_t j;

	while (i < len && s[i] != '\0')
	{
		n = 0;
		j = 0;
		if (s[i] == s1[n])
		{
			while (i < len)
			{
				if (s1[n] == '\0' || s[i] == '\0')
					break ;
				if (s[i] == s1[n])
					j++;
				i++;
				n++;
			}
			if (j == n && j == ft_strlen(s1))
				return ((char *)(s + (i - j)));
		}
		i = i - n + 1;
	}
	return (NULL);
}

char			*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (lit[i] == '\0')
		return ((char *)big);
	if (lit == NULL || big[i] == '\0')
		return (NULL);
	if (i < len)
	{
		str = ft_check(i, big, lit, len);
		if (str != NULL)
			return (str);
	}
	return (NULL);
}
