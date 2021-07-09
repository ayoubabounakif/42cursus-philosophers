/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:46:12 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 11:46:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <signal.h>
# include "../utilsLib/utilsLib.h"

# define __EVENACCESS

# define EATING 1
# define PHILOSOPHER_CAN_DIE 0
# define DEAD 0

typedef struct s_status	t_status;
typedef struct s_philo	t_philo;

struct s_philo
{
	pid_t			pid;
	int				id;
	int				isEating;
	uint64_t		lastMeal;
	t_status		*status;
};

struct s_status
{
	int				numberOfPhilosophers;
	uint64_t		timeToDie;
	uint64_t		timeToEat;
	uint64_t		timeToSleep;
	int				numberOfTimesMustEat;
	uint64_t		startingTime;
	sem_t			*eat;
	sem_t			*write;
	sem_t			*supervisorCounter;
	sem_t			*forks;
	t_philo			*philos;
};

/*
**	subroutines
*/
int			Constructor(t_status *status, int ac, char **av);
t_philo		*philosophersConstructor(t_status *status);
void		semaphoreConstructor(t_status *status);
void		runProcesses(t_status *status);
void		Destructor(t_status *status, void (*del)(void *));

/*
**	supervisor
*/
void		*threadsSupervisor(void *arg);

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
void		ft_usleep(uint64_t sleep_time);

#endif
