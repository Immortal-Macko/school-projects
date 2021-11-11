/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:33:41 by flouie            #+#    #+#             */
/*   Updated: 2021/01/27 02:33:23 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(char *str, int *i, int len)
{
	int	minus;
	int	zero;

	minus = 0;
	zero = 0;
	while (*i < len)
	{
		if (str[*i] != '-' && str[*i] != '0')
			break ;
		if (str[*i] == '0')
			zero++;
		if (str[*i] == '-')
			minus++;
		*i = *i + 1;
	}
	if ((zero && minus) || *i == len || zero > 1 || minus > 1)
		return (-1024);
	if (minus && !zero)
		return (1);
	if (zero && !minus)
		return (0);
	if (!zero && !minus)
		return (-1);
	return (-1024);
}

int		ft_get_width(char *str, int *i, va_list param, t_list *node)
{
	node->width = -1;
	if (str[*i] == '*' && str[*i + 1] != '*' && str[*i + 1] != '\0')
	{
		node->width = va_arg(param, int);
		if (node->width < 0)
			node->flag = 1;
		if (node->width < 0)
			node->width = -1 * node->width;
		*i = *i + 1;
		return (node->width);
	}
	if ((str[*i] == '*' && str[*i + 1] == '*') || str[*i] == '\0')
		return (-1024);
	if (str[*i] >= '0' && str[*i] <= '9')
		node->width = 0;
	while (*i < node->newstart)
	{
		if (str[*i] < '0' || str[*i] > '9')
			break ;
		node->width = node->width * 10 + (str[*i] - 48);
		*i = *i + 1;
	}
	if (*i == node->newstart)
		return (-1024);
	return (node->width);
}

int		ft_get_prec(char *str, int *i, va_list param, t_list *node)
{
	node->prec = 0;
	if (str[*i] != '.' && str[*i] != '\0')
		return ((node->prec = -1));
	if (str[*i] != '\0')
		*i = *i + 1;
	if (str[*i] == '*' && str[*i + 1] != '\0')
	{
		if ((node->prec = va_arg(param, int)) < 0)
			node->prec = -1;
		*i = *i + 1;
		return (node->prec);
	}
	if (str[*i] < '0' && str[*i] > '9')
		return (0);
	while (*i < node->newstart)
	{
		if (str[*i] < '0' || str[*i] > '9')
			break ;
		node->prec = node->prec * 10 + (str[*i] - 48);
		*i = *i + 1;
	}
	if (*i == node->newstart)
		return (-1024);
	return (node->prec);
}

char	ft_get_type(char *str, int *i)
{
	char type;

	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd' ||\
	str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X')
	{
		type = str[*i];
		*i = *i + 1;
	}
	else
		type = '0';
	return (type);
}
