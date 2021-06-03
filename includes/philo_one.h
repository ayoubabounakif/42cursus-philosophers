#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
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

	int			started_eating;

	t_philo		*philos;
}				t_status;


/*
** Init
*/
t_status	*init(t_status *status, int ac, char **av);

#endif
