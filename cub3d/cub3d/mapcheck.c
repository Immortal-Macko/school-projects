#include "cub3d.h"

void	ft_find_pos(char **map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'W'\
				|| map[i][j] == 'E')
				check++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '2')
				ft_error(2);
			j++;
		}
		i++;
	}
	if (check > 1 || check == 0)
		ft_error(2);
}

int	ft_check_string(char **map, int i, int j)
{
	if (i < 0 || j < 0 || j >= (int)(ft_strlen(map[i])))
		ft_error(2);
	if (!map[i] || !map[i][j])
		ft_error(2);
	if ((i == 0 || j == 0) && map[i][j] != '1')
		ft_error(2);
	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&\
	map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E' \
	&& map[i][j] != '2')
		ft_error(2);
	return (1);
}

int	ft_check_around(char **map, int i, int j)
{
	if (!(ft_check_string(map, i, j - 1)))
		ft_error(2);
	if (!(ft_check_string(map, i, j + 1)))
		ft_error(2);
	if (!(ft_check_string(map, i - 1, j - 1)))
		ft_error(2);
	if (!(ft_check_string(map, i - 1, j + 1)))
		ft_error(2);
	if (!(ft_check_string(map, i - 1, j)))
		ft_error(2);
	if (!(ft_check_string(map, i + 1, j - 1)))
		ft_error(2);
	if (!(ft_check_string(map, i + 1, j + 1)))
		ft_error(2);
	if (!(ft_check_string(map, i + 1, j)))
		ft_error(2);
	return (1);
}

static int	ft_valid(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'S' ||\
		map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'E')
			ft_check_around(map, i, j);
		j++;
	}
	return (0);
}

void	ft_checkmap(char **map, int i, int j)
{
	while (map[i + 1] != NULL)
	{
		ft_valid(map, i);
		i++;
	}
	j = -1;
	while (map[i][++j] != '\0')
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '	')
			ft_error(2);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ' || map[i][j] == '	')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	ft_find_pos(map);
}
