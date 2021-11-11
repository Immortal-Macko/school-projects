#include "cub3d.h"

static int	ft_keycond(int keycode, t_info *pn)
{
	if ((keycode == 13 || keycode == 126) && pn->map[(int)((pn->plr->y + \
	sin(pn->plr->dir) * (pn->sz / 2)) / pn->sz)][(int)((pn->plr->x + cos(pn->plr \
	->dir) * (pn->sz / 2)) / pn->sz)] != '1')
		return (1);
	if (keycode == 10000 && pn->map[(int)((pn->plr->y + \
	sin(pn->plr->dir + M_PI_2) * (pn->sz / 2)) / pn->sz)][(int)((pn->plr->x + \
	cos(pn->plr->dir + M_PI_2) * (pn->sz / 2)) / pn->sz)] != '1')
		return (1);
	if ((keycode == 1 || keycode == 125) && pn->map[(int)((pn->plr->y - \
	sin(pn->plr->dir) * (pn->sz / 2)) / pn->sz)][(int)((pn->plr->x - cos(pn-> \
	plr->dir) * (pn->sz / 2)) / pn->sz)] != '1' && pn->plr->y - sin(pn->plr->dir) \
	* (pn->sz / 2) > 0 && pn->plr->x - cos(pn->plr->dir) * (pn->sz / 2) > 0)
		return (1);
	if (keycode == 10001 && pn->map[(int)((pn->plr->y - \
	sin(pn->plr->dir + M_PI_2) * (pn->sz / 2)) / pn->sz)][(int)((pn->plr->x - \
	cos(pn->plr->dir + M_PI_2) * (pn->sz / 2)) / pn->sz)] != '1' && pn->plr->y \
	- sin(pn->plr->dir + M_PI_2) * (pn->sz / 2) >= 0 && pn->plr->x - \
	cos(pn->plr->dir + M_PI_2) * (pn->sz / 2) > 0)
		return (1);
	return (0);
}

int	ft_keyrelease(int keycode, t_info *pn)
{
	if (keycode == 0 || keycode == 123)
		pn->plr->lk = 0;
	if (keycode == 2 || keycode == 124)
		pn->plr->rk = 0;
	return (0);
}

static void	ft_move(int flag, t_info *pn)
{
	if (flag == 1)
		ft_forward(pn);
	if (flag == 2)
	{
		pn->plr->y -= sin(pn->plr->dir) * (pn->sz / 2);
		pn->plr->x -= cos(pn->plr->dir) * (pn->sz / 2);
	}
	if (flag == 3)
	{
		if (pn->plr->rk == 1 && (ft_keycond(10001, pn)) == 1)
		{
			pn->plr->x -= cos(pn->plr->dir + M_PI_2) * (pn->sz / 2);
			pn->plr->y -= sin(pn->plr->dir + M_PI_2) * (pn->sz / 2);
		}
		else
			pn->plr->dir -= 0.1;
	}
	else if (flag == 4)
	{
		if (pn->plr->rk == 1 && (ft_keycond(10000, pn)) == 1)
		{
			pn->plr->x += cos(pn->plr->dir + M_PI_2) * (pn->sz / 2);
			pn->plr->y += sin(pn->plr->dir + M_PI_2) * (pn->sz / 2);
		}
	}
}

int	ft_key(int keycode, t_info *pn)
{
	mlx_clear_window(pn->mlx, pn->win);
	if ((keycode == 13 || keycode == 126) && (ft_keycond(keycode, pn)) == 1)
		ft_move(1, pn);
	if ((keycode == 1 || keycode == 125) && (ft_keycond(keycode, pn)) == 1)
		ft_move(2, pn);
	if (keycode == 0 || keycode == 123)
	{
		pn->plr->lk = 1;
		ft_move(3, pn);
	}
	if (keycode == 2 || keycode == 124)
	{
		pn->plr->rk = 1;
		if (pn->plr->lk == 1)
			ft_move(4, pn);
		else
			pn->plr->dir += 0.1;
	}
	mlx_destroy_image(pn->mlx, pn->img->img);
	if (keycode == 53)
		ft_clear(pn);
	ft_new_image(pn);
	return (0);
}

double	ft_get_value(t_info *pn, t_plr *plr)
{
	double	tmp;

	tmp = 0;
	if (pn->side == 3 || pn->side == 4)
		tmp = plr->x;
	else
		tmp = plr->y;
	return (tmp);
}
