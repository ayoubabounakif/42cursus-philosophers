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
	t_philo	*philos;

	philos = (t_philo *)(arg);
	// printf("%d\n", status->philos->)
	// printf("isEating in supervisorr = %d\n", philos->isEating);
	while (420)
	{
		if (philos->isEating == PHILOSOPHER_CAN_DIE)
		{
			if (getCurrentTime() - philos->lastMeal >= philos->status->timeToDie)
			{
				displayChangeOfStatus("died", philos);
				exit(1);
			}
		}
		ft_usleep(100);
	}
	return (EXIT_SUCCESS);
}
