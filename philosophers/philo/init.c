#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
		data->num_of_philo);
	if (!data->forks)
		return (0);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_message, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (1);
}

int	init_philosophers(t_data *data, int i)
{
	while (i < data->num_of_philo)
	{
		data->philo[i].index = i;
		data->philo[i].times_ate = 0;
		data->philo[i].last_meal_time = get_current_time();
		data->philo[i].data = data;
		data->philo[i].full_flag = 0;
		pthread_create(&(data->philo[i].philo_thread), NULL, routine, \
			(void *)&data->philo[i]);
		ft_usleep(10);
		i += 2;
	}
	return (1);
}

int	check_arg(char **argv)
{
	int		i;
	int		j;
	char	*arg;

	j = 1;
	while (argv[j])
	{
		i = 0;
		arg = argv[j];
		if (arg[0] == '0')
			return (0);
		while (arg && arg[i] != '\0')
		{
			if (arg[i] < '0' || arg[i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

t_data	*fill_arguments(char **argv)
{
	t_data	*data;

	if (!(check_arg(argv)))
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	ft_fill_arg(data, argv);
	data->time_start = get_current_time();
	data->dead_flag = 0;
	if (data->time_to_die < 60 || data->time_to_eat < 60 || \
		data->time_to_sleep < 60 || data->num_of_philo > 200 || \
		!(init_forks(data)))
	{
		free(data);
		return (0);
	}
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	return (data);
}

void	ft_free(t_data **data)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = *data;
	if (tmp && tmp->forks)
	{
		while (i < tmp->num_of_philo)
		{
			pthread_mutex_destroy(&tmp->forks[i]);
			i++;
		}
		pthread_mutex_destroy(&tmp->print_message);
		pthread_mutex_destroy(&tmp->lock);
		free(tmp->forks);
	}
	if (tmp && tmp->philo)
		free(tmp->philo);
	if (tmp)
		free(tmp);
}
