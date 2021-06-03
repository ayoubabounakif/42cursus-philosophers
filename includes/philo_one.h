#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include "../utils/utils.h"

typedef struct	s_philo
{
	int		number;
	int		left_fork;
	int		right_fork;

	pthread_t	thread_id;
}		t_philo;

typedef struct	s_status
{
	int			number_of_philosophers;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			number_of_times_must_eat;

	int		started_eating;

	t_philo		*philo;
}				t_status;


/*
** Init
*/
t_status	*init(t_status *status, int ac, char **av);

// int	init_mutexes(t_state *state)
// {
// 	int	i;

// 	pthread_mutex_init(&state->write_m, NULL);
// 	pthread_mutex_init(&state->somebody_dead_m, NULL);
// 	pthread_mutex_lock(&state->somebody_dead_m);
// 	if (!(state->forks_m =
// 		(pthread_mutex_t*)malloc(sizeof(*(state->forks_m)) * state->amount)))
// 		return (1);
// 	i = 0;
// 	while (i < state->amount)
// 		pthread_mutex_init(&state->forks_m[i++], NULL);
// 	return (0);
// }

// void init_philos(t_state *state)
// {
// 	int	i;

// 	i = 0;
// 	while (i < state->amount)
// 	{
// 		state->philos[i].is_eating = 0;
// 		state->philos[i].position = i;
// 		state->philos[i].lfork = i;
// 		state->philos[i].rfork = (i + 1) % state->amount;
// 		state->philos[i].eat_count = 0;
// 		state->philos[i].state = state;
// 		pthread_mutex_init(&state->philos[i].mutex, NULL);
// 		pthread_mutex_init(&state->philos[i].eat_m, NULL);
// 		pthread_mutex_lock(&state->philos[i].eat_m);
// 		i++;
// 	}
// }

// int init(t_state *state, int argc, char const **argv)
// {
// 	state->amount = ft_atoi(argv[1]);
// 	state->time_to_die = ft_atoi(argv[2]);
// 	state->time_to_eat = ft_atoi(argv[3]);
// 	state->time_to_sleep = ft_atoi(argv[4]);
// 	if (argc == 6)
// 		state->must_eat_count = ft_atoi(argv[5]);
// 	else
// 		state->must_eat_count = 0;
// 	if (state->amount < 2 || state->amount > 200 || state->time_to_die < 60
// 		|| state->time_to_eat < 60 || state->time_to_sleep < 60
// 		|| state->must_eat_count < 0)
// 		return (1);
// 	state->forks_m = NULL;
// 	state->philos = NULL;
// 	if (!(state->philos =
// 		(t_philo*)malloc(sizeof(*(state->philos)) * state->amount)))
// 		return (1);
// 	init_philos(state);
// 	return (init_mutexes(state));
// }

#endif
