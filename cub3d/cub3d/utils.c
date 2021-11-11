#include "cub3d.h"

int	ft_getside(t_plr *plr, t_info *pn, int flag)
{
	if (flag == 1)
	{
		if ((int)plr->x < (int)pn->plr->x)
			pn->side = 1;
		else
			pn->side = 2;
	}
	else
	{
		if ((int)plr->y < (int)pn->plr->y)
			pn->side = 3;
		else if ((double)plr->y > (double)pn->plr->y)
			pn->side = 4;
	}
	return (0);
}

int	ft_clear(t_info *pn)
{
	mlx_hook(pn->win, 17, 1L << 17, ft_clear, pn);
	exit(0);
	return (0);
}

void	ft_error(int flag)
{
	ft_putstr_fd("Error\n", 2);
	if (flag == 1)
		ft_putstr_fd("Invalid configuration file\n", 2);
	if (flag == 2)
		ft_putstr_fd("Invalid map\n", 2);
	if (flag == 3)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	if (flag == 4)
		ft_putstr_fd("Check input arguments\n", 2);
	if (flag == 5)
		ft_putstr_fd("Texture file is not found\n", 2);
	exit(0);
}

int	ft_isitmap(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ' || str[0] == '	' || str[0] == '1')
	{
		while (str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i] == '1')
			return (1);
	}
	return (0);
}
