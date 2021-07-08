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

# include "../../includes/philo.h"

void	__eat__(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->status->forks[philosopher->leftFork]);
	displayChangeOfStatus("has taken the left fork", philosopher);
	pthread_mutex_lock(&philosopher->status->forks[philosopher->rightFork]);
	displayChangeOfStatus("has taken the right fork", philosopher);
	pthread_mutex_lock(&philosopher->eat);
	displayChangeOfStatus("is eating", philosopher);

	/* 	This will be needed by the supervisor */
			/* HARAM Calculations */
	philosopher->isEating = EATING;
	philosopher->lastMeal = getCurrentTime();
	philosopher->numberOfTimesAte += 1;
	if (philosopher->numberOfTimesAte == philosopher->status->numberOfTimesMustEat)
		philosopher->status->supervisorCounter++;
	ft_usleep(philosopher->status->timeToEat * 1000);

	pthread_mutex_unlock(&philosopher->status->forks[philosopher->leftFork]);
	pthread_mutex_unlock(&philosopher->status->forks[philosopher->rightFork]);
	pthread_mutex_unlock(&philosopher->eat);

	philosopher->isEating = PHILOSOPHER_CAN_DIE;
	return ;
}
