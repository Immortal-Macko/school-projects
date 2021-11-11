#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments\n"));
	data = fill_arguments(argv);
	if (!data)
		return (ft_error("Invalid arguments\n"));
	init_philosophers(data, 0);
	init_philosophers(data, 1);
	while (1)
	{
		if ((check_state(data)))
		{
			ft_free(&data);
			return (0);
		}
	}
	return (0);
}
