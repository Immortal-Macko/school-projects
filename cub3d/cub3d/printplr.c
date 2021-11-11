#include "cub3d.h"

static void	ft_renew(t_plr *plr, t_info *pn, int flag, double x)
{
	if (flag == 1)
	{
		plr->x = pn->plr->x;
		plr->y = pn->plr->y;
		pn->spr->end = 0;
	}
	if (flag == 2)
	{
		if (pn->spr->start == 1 && pn->spr->step < pn->spr->hight && \
		pn->spr->x > 0 && pn->spr->x < pn->wid - pn->spr->hight)
			ft_print_sprite(pn->spr->hight, pn, pn->spr->x + pn->spr->step, \
			(int)pn->spr->y);
	}
	if (flag == 3)
	{
		ft_print_walls(pn, x, (int)(plr->y / pn->sz + \
		pn->hght / 3), plr);
	}
	if (flag == 4)
	{
		if (pn->spr->end == 0)
			pn->spr->start = 0;
	}
}

static void	ft_sprcoord(t_plr *plr, t_info *pn, double x)
{
	if (pn->spr->start == 0)
	{
		pn->spr->start = 1;
		pn->spr->step = 0;
		pn->spr->y = (plr->y / pn->sz + pn->hght / 3);
		pn->spr->x = x;
		pn->spr->hight = (int)((double)(pn->hght * (pn->sz / 1.4)) / \
		(ft_raylen(plr->x, pn->plr->x, plr->y, pn->plr->y) * \
		(cos((pn->plr->dir - plr->view_start) * 0.8))));
	}
	pn->spr->end++;
}

double	ft_raylen(double x, double xx, double y, double yy)
{
	double	len;

	len = (double)sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
	return (len);
}

static void	ft_plr_init(t_plr *plr, t_info *pn)
{
	pn->spr->start = 0;
	pn->spr->step = 0;
	pn->spr->end = 0;
	plr->view_start = plr->dir - M_PI_4;
	plr->view_end = plr->dir + M_PI_4;
	pn->spr->x = 0;
}

void	ft_print_plr(t_info *pn, double x)
{
	t_plr	plr;

	plr = *pn->plr;
	ft_plr_init(&plr, pn);
	while (plr.view_start <= plr.view_end)
	{
		ft_renew(&plr, pn, 1, x);
		while (pn->map[(int)(plr.y / pn->sz)][(int)(plr.x / pn->sz)] != '1')
		{
			if (pn->map[(int)(plr.y / pn->sz)][(int)(plr.x / pn->sz)] == '2')
				ft_sprcoord(&plr, pn, x);
			plr.x += cos(plr.view_start);
			if (pn->map[(int)(plr.y / pn->sz)][(int)(plr.x / pn->sz)] == '1' \
				&& (ft_getside(&plr, pn, 1)) == 0)
				break ;
			plr.y += sin(plr.view_start);
			if (pn->map[(int)(plr.y / pn->sz)][(int)(plr.x / pn->sz)] == '1')
				ft_getside(&plr, pn, 2);
		}
		ft_renew(&plr, pn, 4, x);
		ft_renew(&plr, pn, 3, x);
		ft_renew(&plr, pn, 2, x);
		x = x + 1;
		plr.view_start += M_PI_2 / pn->wid;
	}
}
