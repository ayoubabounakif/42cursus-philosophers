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

# include "../../includes/philo_one.h"

void	*routine(void *arg)
{
	t_philo	*philosopher = (t_philo *)arg;

	while (1)
	{
		__eat__(philosopher);
		__sleep__(philosopher);
		__think__(philosopher);
		usleep(100);
	}
	return (EXIT_SUCCESS);
}

void	runThreads(t_status *status)
{
	pthread_t	threadId;
	int			i;

	i = -1;
	status->startingTime = getCurrentTime();
	pthread_mutex_init(&status->write, NULL);
	while (++i < status->numberOfPhilosophers)
	{
		pthread_create(&threadId, NULL, &routine, &status->philos[i]);
		usleep(150);
	}
	return ;
}
