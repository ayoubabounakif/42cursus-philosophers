/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runThreads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:50:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philosopher;
	
	philosopher = (t_philo *)arg;
	philosopher->lastMeal = getCurrentTime();
	while (420)
	{
		__eat__(philosopher);
		__sleep__(philosopher);
		__think__(philosopher);
	}
	return (EXIT_SUCCESS);
}

void	runThreads(t_status *status)
{
	pthread_t	threadId;
	int			i;

	i = -1;
	status->startingTime = getCurrentTime();
	pthread_mutex_init(&(status->write), NULL);
	while (++i < status->numberOfPhilosophers)
	{
		pthread_create(&threadId, NULL, &routine, &status->philos[i]);
		ft_usleep(100);
	}
	// i = 0;
	// while (i < status->numberOfPhilosophers)
	// {
	// 	pthread_create(&threadId, NULL, &routine, &status->philos[i]);
	// 	i += 2;
	// }
	// ft_usleep(1000);
	// i = 1;
	// while (i < status->numberOfPhilosophers)
	// {
	// 	pthread_create(&threadId, NULL, &routine, &status->philos[i]);
	// 	i += 2;
	// }
	return ;
}
