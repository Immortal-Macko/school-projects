/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 04:21:39 by flouie            #+#    #+#             */
/*   Updated: 2021/01/27 01:47:01 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_list *node, va_list param)
{
	char	c;
	int		i;

	i = 1;
	c = va_arg(param, int);
	if (node->flag == 0)
		return (-1);
	if (node->flag == 1)
		write(1, &c, 1);
	if (node->width > 1)
		while (--node->width)
		{
			write(1, " ", 1);
			i++;
		}
	if (node->flag != 1)
		write(1, &c, 1);
	return (i);
}

int		ft_print_s(t_list *node, va_list param)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(param, char *);
	if (str == NULL)
		str = "(null)";
	if (node->flag == 0 || !str)
		return (-1);
	len = (int)ft_strlen(str);
	if (node->prec >= 0 && node->prec < len)
		len = node->prec;
	i = len;
	if (node->flag == 1)
		write(1, str, len);
	if ((node->width = node->width - len))
		while (--node->width > -1)
		{
			write(1, " ", 1);
			i++;
		}
	if (node->flag != 1)
		write(1, str, len);
	return (i);
}

int		ft_print_id(t_list *node, va_list param)
{
	int			i;
	long long	arg;
	int			pr;
	int			g;

	arg = va_arg(param, int);
	i = ft_get_length(arg);
	pr = node->prec;
	g = ft_check(node, &i, (long long)arg, pr);
	if (node->flag == 1 && (arg != 0 || pr != 0))
		ft_putnbr(arg, node, &i);
	if (node->flag == 0 && arg < 0 && pr < 0 && (arg = -1 * arg) > 0)
		write(1, "-", 1);
	if (node->width > 0)
		while (--node->width > -1)
		{
			if (node->flag == 0 && pr == -1)
				write(1, "0", 1);
			if (node->flag != 0 || (node->flag == 0 && pr != -1))
				write(1, " ", 1);
			g++;
		}
	if (node->flag != 1 && (arg != 0 || pr != 0))
		ft_putnbr(arg, node, &i);
	return (i + g);
}

int		ft_print_u(t_list *node, va_list param)
{
	int				i;
	unsigned int	arg;
	int				pr;
	int				g;

	arg = va_arg(param, int);
	pr = node->prec;
	i = ft_get_length((long long)arg);
	g = ft_check(node, &i, (long long)arg, pr);
	if (node->flag == 1 && (arg != 0 || pr != 0))
		ft_putnbr(arg, node, &i);
	if (node->width > 0)
		while (--node->width > -1)
		{
			if (node->flag == 0 && pr == -1)
				write(1, "0", 1);
			if (node->flag != 0 || (node->flag == 0 && pr != -1))
				write(1, " ", 1);
			g++;
		}
	if (node->flag != 1 && (arg != 0 || pr != 0))
		ft_putnbr(arg, node, &i);
	return (i + g);
}

int		ft_print_x(t_list *node, va_list param, char c)
{
	int				i;
	unsigned int	arg;
	int				pr;
	int				g;

	c = ' ';
	arg = va_arg(param, int);
	pr = node->prec;
	i = ft_itoa_x((unsigned long long)arg, node->type, 0, node);
	g = ft_check(node, &i, (long long)arg, pr);
	if (node->flag == 1 && (arg != 0 || pr != 0))
		i = ft_itoa_x((unsigned long long)arg, node->type, 1, node);
	if (node->flag == 0 && pr == -1)
		c = '0';
	if (node->width > 0)
		while (--node->width > -1)
		{
			write(1, &c, 1);
			g++;
		}
	if (node->flag != 1 && (arg != 0 || pr != 0))
		i = ft_itoa_x((unsigned long long)arg, node->type, 1, node);
	return (i + g);
}
