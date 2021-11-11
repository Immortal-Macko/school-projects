#include "philo.h"

void	ft_usleep(unsigned long long time)
{
	unsigned long long	tmp;

	tmp = get_current_time();
	while (get_current_time() - tmp < time)
		usleep(1);
}

int	is_philo_dead(t_data *data, t_philo *philo)
{
	int	time;

	time = get_current_time() - philo->last_meal_time;
	if (time > data->time_to_die)
	{
		data->dead_flag = 1;
		pthread_mutex_lock(&data->lock);
		print_message(data, "died", philo->index);
		pthread_mutex_lock(&data->print_message);
		ft_detach(data);
		return (0);
	}
	return (1);
}

int	check_state(t_data *data)
{
	int	i;
	int	num_of_meals;
	int	times_ate;

	i = 0;
	times_ate = 0;
	num_of_meals = data->num_of_philo * data->num_to_eat;
	while (i < data->num_of_philo)
	{
		times_ate += data->philo[i].times_ate;
		if (!(is_philo_dead(data, data->philo + i)))
			return (1);
		if (data->num_to_eat)
		{
			if (times_ate >= num_of_meals)
			{
				pthread_mutex_lock(&data->lock);
				printf("Philosophers ate %d times each\n", data->num_to_eat);
				ft_detach(data);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	lock_forks(t_philo *philo, t_data *data)
{
	philo->left_fork = philo->index;
	philo->right_fork = philo->index - 1;
	if (philo->index == 0)
		philo->right_fork = philo->data->num_of_philo - 1;
	if (philo->left_fork < philo->right_fork)
	{
		philo->left_fork = philo->right_fork;
		philo->right_fork = philo->index;
	}
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	print_message(data, "has taken a right fork", philo->index);
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	print_message(data, "has taken a left fork", philo->index);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->full_flag && !philo->data->dead_flag)
	{
		lock_forks(philo, philo->data);
		philo->last_meal_time = get_current_time();
		print_message(philo->data, "is eating", philo->index);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		philo->times_ate++;
		if (philo->times_ate == philo->data->num_to_eat)
		{
			philo->full_flag = 1;
			break ;
		}
		print_message(philo->data, "is sleeping", philo->index);
		ft_usleep(philo->data->time_to_sleep);
		print_message(philo->data, "is thinking", philo->index);
	}
	return (NULL);
}
