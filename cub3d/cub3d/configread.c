#include "cub3d.h"

char	**ft_config(t_list **head, int size)
{
	char	**conf;
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *head;
	conf = ft_calloc(size + 1, sizeof(char *));
	if (!conf)
		return (NULL);
	conf[size] = NULL;
	while (ptr)
	{
		conf[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	return (conf);
}

static void	ft_mapcondition(t_info *pn, char *map, int x, int y)
{
	int		j;

	j = 0;
	if (*map == 'S' || *map == 'N' || *map == 'W' || *map == 'E')
	{
		pn->plr->symb = *map;
		*map = '0';
		pn->plr->x = x;
		pn->plr->y = y;
		if (pn->plr->symb == 'N')
			pn->plr->dir = M_PI + M_PI_2;
	}
}

void	ft_read_map(t_info *pn, char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (map[i])
	{
		x = 0;
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_mapcondition(pn, map[i] + j, x, y);
			x = x + (pn->sz);
			j++;
		}
		y = y + (pn->sz);
		i++;
	}
	if (pn->plr->symb == 'S')
		pn->plr->dir = M_PI_2;
	if (pn->plr->symb == 'W')
		pn->plr->dir = M_PI;
}

static void	ft_rescheck(t_info *pn)
{
	if (pn->wid > 4000)
		pn->wid = 4000;
	if (pn->hght > 2500)
		pn->hght = 2500;
	if (pn->hght == -1 || pn->wid == -1)
		ft_error(1);
}

int	pars_res(t_info *pn, char *str, int flag, int g)
{
	int		i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			ft_error(1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			g = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
				g++;
			}
			if (pn->hght == -1 && pn->wid != -1)
				pn->hght = ft_to_int(str + i - g);
			if (pn->wid == -1)
				pn->wid = ft_to_int(str + i - g);
		}
		else
			i++;
	}
	ft_rescheck(pn);
	return (flag + 1);
}
