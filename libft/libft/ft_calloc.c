/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:15:38 by flouie            #+#    #+#             */
/*   Updated: 2020/11/19 19:16:43 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *str;

	str = (void *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
