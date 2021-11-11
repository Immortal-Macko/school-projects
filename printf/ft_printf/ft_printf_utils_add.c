/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:45:28 by flouie            #+#    #+#             */
/*   Updated: 2021/01/27 02:56:06 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check(t_list *node, int *i, long long arg, int pr)
{
	if (arg == 0 && pr == 0)
		*i = 0;
	if (node->flag == 0 && node->prec >= 0)
		node->flag = -1;
	if (node->prec > 0 && arg < 0 && node->prec >= (*i - 1))
		node->prec = node->prec + 1;
	if (node->prec > *i)
		node->width = node->width - node->prec;
	if (node->prec <= *i)
		node->width = node->width - *i;
	return (0);
}

int		ft_print_p(t_list *node, va_list param)
{
	void	*ptr;
	int		i;
	int		j;

	if (node->prec != -1)
		return (-1);
	ptr = va_arg(param, void *);
	i = ft_itoa_p((unsigned long long)ptr, 0) + 2;
	if (node->flag == 1)
		i = ft_itoa_p((unsigned long long)ptr, 1) + 2;
	if ((node->width = node->width - i))
		while (--node->width > -1)
		{
			write(1, " ", 1);
			i++;
		}
	if (node->flag != 1)
		j = ft_itoa_p((unsigned long long)ptr, 1) + 2;
	return (i);
}

int		ft_write(t_list *nd, int n, char *str, int g)
{
	if ((nd->prec = nd->prec - ft_strlen(str + n)) > 0)
		while (--nd->prec > -1 && ++g)
			write(1, "0", 1);
	write(1, str + n, ft_strlen(str + n));
	return (g);
}
