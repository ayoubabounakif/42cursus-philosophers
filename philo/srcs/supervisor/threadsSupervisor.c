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

# include "../../includes/philo.h"

int	threadsSupervisor(t_status *status)
{
	int		i;

	while (420)
	{
		i = -1;
		while (++i < status->numberOfPhilosophers)
		{
			if (status->philos[i].isEating == PHILOSOPHER_CAN_DIE)
			{
				pthread_mutex_lock(&status->philos[i].eat);
				if (getCurrentTime() - status->philos[i].lastMeal >= status->timeToDie)
				{
					displayChangeOfStatus("died", status->philos);
					// Destructor(status, free);
					return (EXIT_SUCCESS);
				}
				else if (status->supervisorCounter == status->numberOfPhilosophers)
				{
					// Destructor(status, free);
					return (EXIT_SUCCESS);
				}
				pthread_mutex_unlock(&status->philos[i].eat);
			}
		}
		ft_usleep(100);
	}
	return (EXIT_SUCCESS);
}
