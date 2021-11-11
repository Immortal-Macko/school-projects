#include "cub3d.h"

int	ft_check_input(int argc, char **argv)
{
	int		i;
	int		flag;

	i = 0;
	flag = -1;
	if (argc > 3 || argc < 2)
		ft_error(3);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0))
		ft_error(4);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '.' && argv[1][i + 1] == 'c' && argv[1][i + 2] ==\
		'u' && argv[1][i + 3] == 'b' && argv[1][i + 4] == '\0')
			flag = 0;
		i++;
	}
	if (argc == 3 && flag == 0 && (ft_strncmp(argv[2], "--save", 6) == 0) \
		&& argv[2][6] == '\0')
		flag = 1;
	if (flag == -1)
		ft_error(4);
	return (flag);
}

static void	ft_writeheader(int fd, int i, int size, t_info *pn)
{
	char	str[54];

	while (++i < 54)
		str[i] = 0;
	str[0] = 'B';
	str[1] = 'M';
	str[2] = (char)(size % 256);
	str[3] = (char)(size / 256 % 256);
	str[4] = (char)(size / 256 / 256 % 256);
	str[5] = (char)(size / 256 / 256 / 256);
	str[10] = 54;
	str[14] = 40;
	str[18] = (char)(pn->wid % 256);
	str[19] = (char)(pn->wid / 256 % 256);
	str[20] = (char)(pn->wid / 256 / 256 % 256);
	str[21] = (char)(pn->wid / 256 / 256 / 256);
	str[22] = (char)(pn->hght % 256);
	str[23] = (char)(pn->hght / 256 % 256);
	str[24] = (char)(pn->hght / 256 / 256 % 256);
	str[25] = (char)(pn->hght / 256 / 256 / 256);
	str[26] = 1;
	str[28] = 32;
	write(fd, str, 54);
}

void	ft_bmp(t_info *pn)
{
	int		fd;
	int		size;
	int		i;

	fd = open("bit_map.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0744);
	size = pn->wid * pn->hght * 4 + 14 + 40;
	ft_writeheader(fd, -1, size, pn);
	size = pn->hght - 1;
	while (size >= 0)
	{
		i = 0;
		while (i < pn->img->sl)
		{
			write(fd, pn->img->addr + size * pn->img->sl + i, 1);
			i++;
		}
		size--;
	}
	ft_clear(pn);
}

void	ft_mlx(t_info *pn, int flag)
{
	pn->mlx = mlx_init();
	pn->win = mlx_new_window(pn->mlx, pn->wid, pn->hght, "CUB3D");
	if (pn->wid < 800)
		pn->sz = pn->wid / 10;
	else
		pn->sz = pn->wid / 20;
	pn->img->img = mlx_new_image(pn->mlx, pn->wid, pn->hght);
	pn->img->addr = mlx_get_data_addr(pn->img->img, &pn->img->bpp, \
	&pn->img->sl, &pn->img->en);
	ft_read_map(pn, pn->map);
	ft_print_plr(pn, 0);
	if (flag != 1)
	{
		ft_first_line(pn);
		mlx_put_image_to_window(pn->mlx, pn->win, pn->img->img, \
		pn->x, pn->y);
	}
	else
		ft_bmp(pn);
}

void	ft_new_image(t_info *pn)
{
	pn->img->img = mlx_new_image(pn->mlx, pn->wid, pn->hght);
	pn->img->addr = mlx_get_data_addr(pn->img->img, &pn->img->bpp, \
	&pn->img->sl, &pn->img->en);
	ft_print_plr(pn, 0);
	ft_first_line(pn);
	mlx_put_image_to_window(pn->mlx, pn->win, pn->img->img, pn->x, pn->y);
}
