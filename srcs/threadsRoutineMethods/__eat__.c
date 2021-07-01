/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __eat__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:51:52 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:52:06 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

void	__eat__(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->status->forks[philosopher->leftFork]);
	displayChangeOfStatus("has taken the left fork", philosopher);

	pthread_mutex_lock(&philosopher->status->forks[philosopher->rightFork]);
	displayChangeOfStatus("has taken the right fork", philosopher);

	pthread_mutex_lock(&philosopher->eat);
	displayChangeOfStatus("is eating", philosopher);

	/* 	This will be needed by the supervisor */
	philosopher->lastMeal = getCurrentTime();
	philosopher->isEating = EATING;
	philosopher->numberOfTimesAte += 1;
	if (philosopher->numberOfTimesAte == philosopher->status->numberOfTimesMustEat)
		philosopher->status->supervisorCounter++;

	/* HARAM Calculations */
	usleep(philosopher->status->timeToEat * 1000 - 10000);
	while (getCurrentTime() - philosopher->lastMeal < philosopher->status->timeToEat);

	pthread_mutex_unlock(&philosopher->status->forks[philosopher->leftFork]);
	pthread_mutex_unlock(&philosopher->status->forks[philosopher->rightFork]);
	pthread_mutex_unlock(&philosopher->eat);
	philosopher->isEating = PHILOSOPHER_CAN_DIE;
	return ;
}
