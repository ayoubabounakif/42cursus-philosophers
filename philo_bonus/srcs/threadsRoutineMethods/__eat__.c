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

# include "../../includes/philo_bonus.h"

void	__eat__(t_philo *philosopher)
{
	sem_wait(philosopher->status->forks);
	displayChangeOfStatus("has taken the left fork", philosopher);
	sem_wait(philosopher->status->forks);
	displayChangeOfStatus("has taken the right fork", philosopher);
	sem_wait(philosopher->status->eat);
	displayChangeOfStatus("is eating", philosopher);

	/* 	This will be needed by the supervisor */
			/* HARAM Calculations */
	philosopher->isEating = EATING;
	philosopher->lastMeal = getCurrentTime();
	ft_usleep(philosopher->status->timeToEat * 1000);
	philosopher->isEating = PHILOSOPHER_CAN_DIE;

	sem_post(philosopher->status->forks);
	sem_post(philosopher->status->forks);
	sem_post(philosopher->status->eat);

	return ;
}
