/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:53:03 by flouie            #+#    #+#             */
/*   Updated: 2020/11/24 15:33:12 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_local(char const *s)
{
	size_t n;

	n = 0;
	if (s == NULL)
		return (n);
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

static size_t	ft_start(char const *s1, char const *set, size_t len, size_t n)
{
	size_t i;
	size_t j;
	size_t counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < len)
	{
		j = 0;
		counter = 0;
		while (j < n)
		{
			if (s1[i] == set[j])
				counter++;
			j++;
		}
		if (counter == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set, size_t len, size_t n)
{
	long long	i;
	size_t		j;
	size_t		counter;

	i = (long long)len - 1;
	j = 0;
	counter = 0;
	while (i >= 0)
	{
		j = 0;
		counter = 0;
		while (j < n)
		{
			if (s1[i] == set[j])
				counter++;
			j++;
		}
		if (counter == 0)
			break ;
		i--;
	}
	if (i == -1)
		i = 0;
	return ((size_t)i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	setlen;
	char	*str;
	size_t	start;
	size_t	end;

	str = NULL;
	if (s1 == NULL || set == NULL)
		return (str);
	slen = ft_strlen_local(s1);
	setlen = ft_strlen_local(set);
	if (s1[0] == '\0')
	{
		str = (char *)ft_calloc(1, sizeof(char));
		return (str);
	}
	if (set[0] == '\0')
		return (ft_substr(s1, 0, slen));
	start = ft_start(s1, set, slen, setlen);
	end = ft_end(s1, set, slen, setlen);
	if (start > end)
		str = (char *)ft_calloc(1, sizeof(char));
	else
		str = ft_substr(s1, (unsigned int)start, end - start + 1);
	return (str);
}
