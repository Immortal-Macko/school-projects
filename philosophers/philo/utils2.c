#include "philo.h"

void	ft_detach(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_detach(data->philo[i].philo_thread);
		i++;
	}
}

void	ft_fill_arg(t_data *data, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_to_eat = ft_atoi(argv[5]);
	else
		data->num_to_eat = 0;
}

int	ft_error(char *str)
{
	printf("%s", str);
	return (-1);
}
