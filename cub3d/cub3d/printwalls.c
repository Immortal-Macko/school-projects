#include "cub3d.h"

int	ft_get_texture(t_texture *txt, char *path, void *mlx)
{
	int	wid;
	int	hght;

	if (path)
	{
		txt->img = mlx_xpm_file_to_image(mlx, path, &wid, &hght);
		txt->width = wid;
		txt->hight = hght;
		if (txt->img)
		{
			txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, \
			&txt->sl, &txt->en);
		}
		else
			return (-1);
	}
	return (0);
}

static	t_texture	*ft_gettextside(t_info *pn)
{
	if (pn->side == 1)
		return (pn->wtxt);
	else if (pn->side == 2)
		return (pn->etxt);
	else if (pn->side == 3)
		return (pn->ntxt);
	else if (pn->side == 4)
		return (pn->stxt);
	return ((t_texture *) NULL);
}

static int	ft_getcolor(int x, int wall_hight, t_info *pn, int i)
{
	char		*ptr;
	int			color;
	int			tmp;
	t_texture	*txt;

	txt = ft_gettextside(pn);
	color = 0;
	tmp = (int)(i * ((double)txt->hight / ((double)wall_hight)));
	ptr = txt->addr + txt->sl * tmp + (x % 64) * (txt->bpp / 8);
	color += *(unsigned int *)ptr;
	return (color);
}

void	ft_print_walls(t_info *pn, double x, int y, t_plr *plr)
{
	int		wall_hight;
	double	tmp;
	int		i;
	int		cof;

	i = 0;
	wall_hight = (int)((double)(pn->hght * (pn->sz / 1.6)) / \
	(ft_raylen(plr->x, pn->plr->x, plr->y, pn->plr->y) * \
	(cos((pn->plr->dir - plr->view_start) * 0.8))));
	y = y - (wall_hight / 2);
	cof = wall_hight;
	tmp = ft_get_value(pn, plr);
	ft_print_cel(pn, x, y);
	while (wall_hight && y < pn->hght)
	{
		if (y >= 0)
			ft_pixel_put(pn->img, x, y, ft_getcolor((int)tmp, \
			cof, pn, i));
		i++;
		y++;
		wall_hight--;
	}
	ft_print_floor(pn, x, y);
}

void	ft_forward(t_info *pn)
{
	pn->plr->y += sin(pn->plr->dir) * (pn->sz / 2);
	pn->plr->x += cos(pn->plr->dir) * (pn->sz / 2);
}
