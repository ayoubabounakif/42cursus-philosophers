#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int		number;
	int		left_fork;
	int		right_fork;

	pthread_t	thread_id;
}		t_philo;

typedef struct	s_status
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_must_eat;

	int		started_eating;

	t_philo		*philo;
}		t_status

#endif
