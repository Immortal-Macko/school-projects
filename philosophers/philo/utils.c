#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	n;
	unsigned int	j;
	long long		num;

	n = 0;
	j = 0;
	num = 0;
	while (((str[n] > 8 && str[n] < 14) || str[n] == ' ') && str[n] != '\0')
	{
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
	{
		j = str[n];
		n++;
	}
	while ((str[n] > 47) && (str[n] < 58))
	{
		num = num * 10 + (str[n] - 48);
		n++;
	}
	if (j == 45)
		num = -1 * num;
	return ((int)num);
}

unsigned long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_message(t_data *data, char *state, int num)
{
	unsigned long long	time;

	pthread_mutex_lock(&data->print_message);
	time = get_current_time() - data->time_start;
	printf("%llu %d %s\n", time, num + 1, state);
	pthread_mutex_unlock(&data->print_message);
}
