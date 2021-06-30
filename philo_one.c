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

void	threadsSupervisor(t_status *status)
{
	int		i;

	i = -1;
	while (1)
	{	
		while (++i < status->numberOfPhilosophers)
		{
			if (getCurrentTime() > status->timeToDie - status->philos->lastMeal
				&& status->philos->isEating == PHILOSOPHER_CAN_DIE)
			{
				// pthread_mutex_unlock(&status->philos->eat);
				// Destructor(status, free);
				displayChangeOfStatus("dead", status->philos);
				return (EXIT_SUCCESS);
			}
		}
	}
	return ;
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
