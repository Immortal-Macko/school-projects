#include "cub3d.h"

void	ft_readconf(t_list **head, char *name)
{
	int		res;
	char	*line;
	int		fd;

	res = 1;
	line = NULL;
	fd = open(name, O_RDONLY);
	while (res)
	{
		res = get_next_line(fd, &line);
		ft_lstadd_back(head, ft_lstnew(line));
	}
	close(fd);
}

static int	ft_isitkey(char *str)
{
	if (str[0] == 'S' || str[0] == 'N' || str[0] == 'W' || str[0] == 'R'\
		|| str[0] == 'E' || str[0] == ' ' || str[0] == '\n' || str[0] == 'F'\
		|| str[0] == 'C' || str[0] == '\0')
		return (1);
	else
		return (-1);
}

void	ft_parser(t_info *pn, char **conf, int i, int stop)
{
	pn->side = 0;
	while (conf[i] && stop != 1)
	{
		if (conf[i][0] == 'R')
			pn->side = pars_res(pn, conf[i], pn->side, 0);
		if (conf[i][0] == 'F')
			pn->side = pars_color(pn, conf[i], pn->side, 2);
		if (conf[i][0] == 'C')
			pn->side = pars_color(pn, conf[i], pn->side, 1);
		if (conf[i][0] == 'S' || conf[i][0] == 'N' || conf[i][0] == 'W' || \
		conf[i][0] == 'E')
			pn->side = pars_texture(pn, (char *)conf[i], pn->side, 0);
		if (pn->side == 8)
			stop = ft_isitmap(conf[i]);
		if (pn->side == 8 && stop > 0)
			pn->map = conf + i;
		if (stop == 1)
			ft_checkmap(pn->map, 0, 0);
		if (conf[i + 1] == NULL && stop == 0)
			pn->side = -1;
		if (!pn->side || (stop == 0 && (ft_isitkey(conf[i])) < 0))
			ft_error(1);
		i++;
	}
}

void	ft_first_line(t_info *pn)
{
	int	i;

	i = 0;
	while (i < pn->hght)
	{
		ft_pixel_put(pn->img, 0, i, 0);
		i++;
	}
}
