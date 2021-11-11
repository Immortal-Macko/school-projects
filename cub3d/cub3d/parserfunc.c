#include "cub3d.h"

static int	ft_skip(char *str, int i, t_color *col)
{
	int	j;

	j = 0;
	if (col->r != -1 && col->g != -1 && col->b == -1)
		col->b = (unsigned int)ft_to_int(str + i);
	if (col->r != -1 && col->g == -1 && col->b == -1)
		col->g = (unsigned int)ft_to_int(str + i);
	if (col->r == -1 && col->g == -1 && col->b == -1)
		col->r = (unsigned int)ft_to_int(str + i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		j++;
		i++;
	}
	return (j);
}

static void	ft_initcolor(t_color *col, t_info *pn, int c)
{
	if (col->r > 255 || col->g > 255 || col->b > 255)
		ft_error(1);
	if (col->r != -1 && col->g != -1 && col->b != -1)
	{
		if (c == 1)
			pn->celling = (int)(col->r << 16 | col->g << 8 | col->b);
		if (c == 2)
			pn->floor = (int)(col->r << 16 | col->g << 8 | col->b);
	}
	if ((c == 1 && !pn->celling) || (c == 2 && !pn->floor))
		ft_error(1);
}

int	pars_color(t_info *pn, char *str, int flag, int c)
{
	t_color	col;
	int		i;

	col.r = -1;
	col.g = -1;
	col.b = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			ft_error(1);
		if (str[i] >= '0' && str[i] <= '9')
			i = i + ft_skip(str, i, &col);
		else
			i++;
	}
	ft_initcolor(&col, pn, c);
	return (flag + 1);
}

static int	ft_parstextcond(char *str, int check, t_info *pn, int i)
{
	if (str[0] == 'N')
		check = ft_get_texture(pn->ntxt, (char *) \
			((pn->ntxt->path = str + i + 1)), pn->mlx);
	else if (str[0] == 'S' && str[1] != 'O')
		check = ft_get_texture(pn->sptxt, (char *) \
			((pn->sptxt->path = str + i + 1)), pn->mlx);
	else if (str[0] == 'S' && str[1] == 'O')
		check = ft_get_texture(pn->stxt, (char *) \
			((pn->stxt->path = str + i + 1)), pn->mlx);
	else if (str[0] == 'W')
		check = ft_get_texture(pn->wtxt, (char *) \
			((pn->wtxt->path = str + i + 1)), pn->mlx);
	else if (str[0] == 'E')
		check = ft_get_texture(pn->etxt, (char *) \
			((pn->etxt->path = str + i + 1)), pn->mlx);
	return (check);
}

int	pars_texture(t_info *pn, char *str, int flag, int i)
{
	int	fd;
	int	check;

	fd = 0;
	check = -1;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i + 1] == '.' && fd == 0)
		{
			fd = open((const char *)str + i + 1, O_RDONLY);
			if (fd > 0)
				check = ft_parstextcond(str, check, pn, i);
		}
		i++;
	}
	if (fd > 0)
		close(fd);
	if (fd == -1 || check == -1)
		ft_error(5);
	return (flag + 1);
}
