/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:50:16 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/03 09:50:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/philo_one.h"

int	threadsSupervisor(t_status *status)
{
	int		i;

	i = -1;
	while (1)
	{
		while (++i < status->numberOfPhilosophers)
		{
			if (getCurrentTime() >= status->timeToDie - status->philos[i].lastMeal
				&& status->philos[i].isEating == PHILOSOPHER_CAN_DIE)
			{
				pthread_mutex_lock(&status->philos[i].eat);
				displayChangeOfStatus("died", status->philos);
				pthread_mutex_unlock(&status->philos[i].eat);
				Destructor(status, free);
				return (EXIT_SUCCESS);
			}
			else if (status->supervisorCounter == status->numberOfPhilosophers)
			{
				Destructor(status, free);
				return (EXIT_SUCCESS);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_status	status;
	
	if (ac < 5 || ac > 6)
			return (printError("Error: Bad arguments number!\n"));
	else
	{
		Constructor(&status, ac, av);
		mutexConstructor(&status);
		runThreads(&status);
		threadsSupervisor(&status);
	}
	return (EXIT_SUCCESS);
}
