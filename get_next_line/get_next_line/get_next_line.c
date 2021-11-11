/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouie <flouie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 01:57:08 by flouie            #+#    #+#             */
/*   Updated: 2021/01/20 03:52:36 by flouie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_check_string(char *string, char **line)
{
	int	flag;
	int len;

	flag = -2;
	len = 0;
	flag = ft_find_n(string);
	if (flag == -1)
		*line = ft_strjoin(line, string);
	if (flag >= 0)
	{
		len = (int)ft_strlen(string);
		string[flag] = '\0';
		*line = ft_strjoin(line, string);
		string = ft_strcopy(string, string + flag + 1, -1, len);
	}
	return (flag);
}

static int	ft_read_line(int fd, char *string, char **line)
{
	int		check;
	int		i;
	char	*buf;

	i = -1;
	check = -1;
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (-1);
	while (i < 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check < 0 || check == 0)
			break ;
		buf[check] = '\0';
		if ((i = ft_find_n(buf)) >= 0)
			buf[i] = '\0';
		*line = ft_strjoin(line, buf);
	}
	if (check != 0 && check != -1)
		string = ft_strcopy(string, buf + i + 1, 1, 0);
	free(buf);
	if (check > 1)
		return (1);
	return (check);
}

int			get_next_line(int fd, char **line)
{
	static char	*string;
	int			flag;
	int			check;

	check = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, NULL, 0)) < 0)
		return (-1);
	*line = ft_calloc(1, 1);
	if (!string)
		string = ft_calloc(BUFFER_SIZE + 1, 1);
	flag = ft_check_string(string, line);
	if (flag < 0)
		check = ft_read_line(fd, string, line);
	if (check == -1 && *line)
		free(*line);
	if (check == -1 || check == 0)
	{
		free(string);
		string = NULL;
	}
	return (check);
}
