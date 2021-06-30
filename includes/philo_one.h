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
# include "../utilsLib/utilsLib.h"

# define __EVENACCESS

# define PHILOSOPHER_CAN_DIE 0
# define EATING 1

typedef struct s_status	t_status;
typedef struct s_philo	t_philo;

struct s_philo
{
	int				id;
	int				leftFork;
	int				rightFork;
	int				numberOfTimesAte;
	int				isEating;

	uint64_t		lastMeal;

	pthread_mutex_t	eat;

	t_status		*status;
};

struct s_status
{
	int				numberOfPhilosophers;
	uint64_t		timeToDie;
	uint64_t		timeToEat;
	uint64_t		timeToSleep;
	int				numberOfTimesMustEat;

	int				supervisorCounter;

	uint64_t		startingTime;

	pthread_mutex_t	write;
	pthread_mutex_t	*forks;

	t_philo			*philos;
};

/*
**	subroutines
*/
t_status	*Constructor(t_status *status, int ac, char **av);
t_philo		*philosophersConstructor(t_status *status);
void		mutexConstructor(t_status *status);
void		runThreads(t_status *status);
void		Destructor(t_status *status, void (*del)(void *));

/*
**	threadsRoutineMethods
*/
void		__eat__(t_philo *philosopher);
void		__sleep__(t_philo *philosopher);
void		__think__(t_philo *philosopher);

/*
**	threadsUtils
*/
uint64_t	getCurrentTime(void);
void		displayChangeOfStatus(char *messageToPrint, t_philo *philosopher);


#endif
