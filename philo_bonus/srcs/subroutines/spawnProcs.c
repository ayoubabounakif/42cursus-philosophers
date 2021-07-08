/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawnProcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:55 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:50:13 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_bonus.h"

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

void	spawnProcs(t_status *status)
{
	int			i;
	int			stat_loc;
	pthread_t	t_id;
	pid_t		wpid;

	i = -1;
	status->startingTime = getCurrentTime();
	while (++i < status->numberOfPhilosophers)
	{
		status->philos[i].pid = fork();
		if (status->philos[i].pid < 0)
			exit(printError("Error forking\n"));
		if (status->philos[i].pid == 0)
		{
			pthread_create(&t_id, NULL, threadsSupervisor, &status->philos[i]);
			routine(&status->philos[i]);
			exit(EXIT_SUCCESS);
		}
		ft_usleep(100);
	}
	while ((wpid = wait(&stat_loc)) > 0);	
	return ;
}
