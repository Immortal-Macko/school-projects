#include "cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	ft_getsprcolor(int x, int wall_hight, t_info *pn, int i)
{
	char		*ptr;
	int			color;
	int			tmp;
	t_texture	*txt;
	double		k;

	txt = pn->sptxt;
	color = 0;
	k = (double)((double)wall_hight / (double)64);
	tmp = (int)(i * ((double)txt->hight / ((double)wall_hight)));
	ptr = txt->addr + txt->sl * tmp + (int)(x / k)*(txt->bpp / 8);
	color += *(unsigned int *)ptr;
	return (color);
}

void	ft_print_sprite(int spr_hight, t_info *pn, double x, int y)
{
	int	i;
	int	cof;
	int	color;

	i = 0;
	y = y - (spr_hight / 2);
	cof = spr_hight;
	if (pn->spr->step < spr_hight * 10)
	{
		while (spr_hight && y < pn->hght)
		{
			if (y >= 0)
			{
				color = ft_getsprcolor((int)pn->spr->step, cof, pn, i);
				if (color > 0)
					ft_pixel_put(pn->img, x, y, color);
			}
			i++;
			y++;
			spr_hight--;
		}
	}
	pn->spr->step++;
}

void	ft_print_cel(t_info *pn, double x, int y)
{
	int	start;

	start = 0;
	while (start < y)
	{
		ft_pixel_put(pn->img, x, start, (int)pn->celling);
		start++;
	}
}

void	ft_print_floor(t_info *pn, double x, int y)
{
	while (y < pn->hght)
	{
		ft_pixel_put(pn->img, x, y, (int)pn->floor);
		y++;
	}
}
