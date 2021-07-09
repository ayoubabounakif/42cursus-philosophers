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
	t_status	*status;

	status = (t_status *)(arg);
	printf("--------------\nisEating inside supervisor --> %d\n--------------\n", status->philos->isEating);
	fflush(stdout);
	while (420)
	{
		// printf("%d\n", status->philos->isEating);
		if (status->philos->isEating == PHILOSOPHER_CAN_DIE)
		{
			if (getCurrentTime() - status->philos->lastMeal >= status->timeToDie)
			{
				displayChangeOfStatus("died", status->philos);
				exit(1);
			}
		}
		ft_usleep(100);
	}
	return (EXIT_SUCCESS);
}
