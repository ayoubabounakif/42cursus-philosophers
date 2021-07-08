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

# include "../../includes/philo_bonus.h"

void	*threadsSupervisor(void *arg)
{
	int			i;
	t_status	*status;

	status = (t_status *)(arg);
	while (420)
	{
		i = -1;
		while (++i < status->numberOfPhilosophers)
		{
			if (status->philos[i].isEating == PHILOSOPHER_CAN_DIE)
			{
				sem_wait(status->eat);
				if (getCurrentTime() - status->philos[i].lastMeal >= status->timeToDie)
				{
					displayChangeOfStatus("died", status->philos);
					// Destructor(status, free);
					exit (EXIT_SUCCESS);
				}
				else if (status->supervisorCounter == status->numberOfPhilosophers)
				{
					// Destructor(status, free);
					exit (EXIT_SUCCESS);
				}
				sem_post(status->eat);
			}
		}
		ft_usleep(100);
	}
	return (EXIT_SUCCESS);
}
