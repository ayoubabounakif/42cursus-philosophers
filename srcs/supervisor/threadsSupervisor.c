/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadsSupervisor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:50:22 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/01 15:50:40 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

int	threadsSupervisor(t_status *status)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < status->numberOfPhilosophers)
		{
			if (getCurrentTime() - status->philos[i].lastMeal >= status->timeToDie
				&& status->philos[i].isEating == PHILOSOPHER_CAN_DIE)
			{
				pthread_mutex_lock(&status->forks[status->philos[i].rightFork]);
				pthread_mutex_lock(&status->forks[status->philos[i].leftFork]);
				pthread_mutex_lock(&status->philos[i].eat);
				displayChangeOfStatus("died", status->philos);
				status->isPhilosopherAlive = DEAD;
				usleep(100000);
				Destructor(status, free);
				return (EXIT_SUCCESS);
			}
			else if (status->supervisorCounter == status->numberOfPhilosophers)
			{
				usleep(100000);
				Destructor(status, free);
				return (EXIT_SUCCESS);
			}
		}
		usleep(100);
	}
	return (EXIT_SUCCESS);
}
