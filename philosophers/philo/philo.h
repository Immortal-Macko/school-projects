#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_philo
{
	pthread_t			philo_thread;
	int					index;
	int					times_ate;
	unsigned long long	last_meal_time;
	int					full_flag;
	int					left_fork;
	int					right_fork;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_to_eat;
	unsigned long long	time_start;
	int					dead_flag;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_message;
	pthread_mutex_t		lock;
	struct s_philo		*philo;
}						t_data;

int					ft_atoi(const char *str);
unsigned long long	get_current_time(void);
void				*routine(void *arg);
void				print_message(t_data *data, char *state, int num);
void				lock_forks(t_philo *philo, t_data *data);
int					init_forks(t_data *data);
int					init_philosophers(t_data *data, int i);
int					check_arg(char **argv);
t_data				*fill_arguments(char **argv);
void				ft_free(t_data **data);
int					is_philo_dead(t_data *data, t_philo *philo);
void				ft_usleep(unsigned long long time);
int					check_state(t_data *data);
void				ft_detach(t_data *data);
void				ft_fill_arg(t_data *data, char **argv);
int					ft_error(char *str);

#endif
