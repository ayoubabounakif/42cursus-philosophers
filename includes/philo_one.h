/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:46:12 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 11:46:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include "../utils/utils.h"

# define __evenaccess

typedef struct s_philo
{
	int				id;
	uint64_t		lastMeal;
	int				leftFork;
	int				rightFork;
	pthread_mutex_t	eat;

	t_status		*status;
}				t_philo;

typedef struct s_status
{
	int				numberOfPhilosophers;
	uint64_t		timeToDie;
	uint64_t		timeToEat;
	uint64_t		timeToSleep;
	int				numberOfTimesMustEat;

	uint64_t		currentTime;

	pthread_mutex_t	write;
	pthread_mutex_t	*forks;

	t_philo			*philos;
}				t_status;


/*
**	Constructor of the two structs above
*/
t_status	*Constructor(t_status *status, int ac, char **av);
t_philo		*philosophersConstructor(t_status *status);
void		mutexConstructor(t_status *status);

/*
**	Starting multi-threading
*/
void		runThreads(t_status *status);

/*
**	Routines
*/
void	__eat__(t_philo *philosopher);

/*
**	Gets the current time
*/
uint64_t	getCurrentTime(void);

#endif
