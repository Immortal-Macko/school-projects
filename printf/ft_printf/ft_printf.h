/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 02:36:39 by flouie            #+#    #+#             */
/*   Updated: 2021/01/27 02:52:52 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_list
{
	int				flag;
	int				width;
	int				prec;
	char			type;
	int				newstart;
}					t_list;

int					ft_printf(const char *str, ...);
size_t				ft_strlen(const char *s);
void				ft_putnbr(long long n, t_list *node, int *i);
int					ft_get_length(long long value);
int					ft_itoa_x(unsigned long long v, char t, int f, t_list *n);
int					ft_write(t_list *nd, int n, char *str, int g);
int					ft_itoa_p(unsigned long long v, int f);
int					ft_print_u(t_list *node, va_list param);
int					ft_check(t_list *node, int *i, long long arg, int pr);
int					ft_get_flag(char *str, int *i, int len);
int					ft_get_width(char *str, int *i, va_list param, t_list *nod);
int					ft_get_prec(char *str, int *i, va_list param, t_list *node);
char				ft_get_type(char *str, int *i);
int					ft_print_c(t_list *node, va_list param);
int					ft_print_s(t_list *node, va_list param);
int					ft_print_id(t_list *node, va_list param);
int					ft_print_x(t_list *node, va_list param, char c);
int					ft_print_u(t_list *node, va_list param);
int					ft_print_p(t_list *node, va_list param);

#endif
