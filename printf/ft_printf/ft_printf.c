#include "ft_printf.h"

static int	ft_print_format(t_list *node, va_list param)
{
	char c;

	c = ' ';
	if (node->type == 'c')
		return (ft_print_c(node, param));
	if (node->type == 's')
		return (ft_print_s(node, param));
	if (node->type == 'd' || node->type == 'i')
		return (ft_print_id(node, param));
	if (node->type == 'x' || node->type == 'X')
		return (ft_print_x(node, param, c));
	if (node->type == 'u')
		return (ft_print_u(node, param));
	if (node->type == 'p')
		return (ft_print_p(node, param));
	return (0);
}

static int	ft_parser(char *str, va_list param, t_list *node)
{
	int		i;
	int		len;

	i = 0;
	if (!str)
		return (-1);
	len = node->newstart + 1;
	node->newstart = (int)ft_strlen(str);
	if ((node->flag = ft_get_flag(str, &i, node->newstart)) == -1024)
		return (-1);
	if ((node->width = ft_get_width(str, &i, param, node)) == -1024)
		return (-1);
	if ((node->prec = ft_get_prec(str, &i, param, node)) == -1024)
		return (-1);
	if ((node->type = ft_get_type(str, &i)) == '0')
		return (-1);
	node->newstart = len + i;
	return (ft_print_format(node, param));
}

static int	ft_printf_str(const char *str, va_list param, t_list *node, int l)
{
	int		n;

	while (node->newstart < (int)ft_strlen(str))
	{
		n = 0;
		if (str[node->newstart] != '%')
		{
			write(1, str + node->newstart, 1);
			node->newstart = node->newstart + 1;
			l++;
		}
		if (str[node->newstart] == '%' && str[node->newstart + 1] != '%')
			n = ft_parser((char *)str + node->newstart + 1, param, node);
		if (n == -1)
			break ;
		l = l + n;
		if (str[node->newstart] == '%' && str[node->newstart + 1] == '%' && ++l)
		{
			write(1, str + node->newstart, 1);
			node->newstart = node->newstart + 2;
		}
	}
	if (n == -1)
		l = -1;
	return (l);
}

int			ft_printf(const char *str, ...)
{
	t_list	*node;
	va_list param;
	int		len;

	len = 0;
	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return (-1);
	node->newstart = 0;
	va_start(param, str);
	len = ft_printf_str(str, param, node, len);
	va_end(param);
	free(node);
	return (len);
}
