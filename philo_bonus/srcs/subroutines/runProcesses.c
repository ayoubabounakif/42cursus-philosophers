/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runProcesses.c                                       :+:      :+:    :+:   */
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

void	*superviserRoutine(void *arg)
{
	t_status	*status;
	int			count;
	// int			i;

	status = (t_status *)arg;
	count = -1;
	// while (++count < status->numberOfTimesMustEat)
	// {
	// 	i = -1;
	// 	while (++i < status->numberOfPhilosophers)
	// 		sem_wait(status->philos[i].eat);
	// }
	// sem_wait(status->write);
	for (int j = 0; j < status->numberOfPhilosophers; j++)
		kill(status->philos[j].pid, SIGKILL);
	return (NULL);
}

void	runProcesses(t_status *status)
{
	int			i;
	int			stat_loc;
	pthread_t	t_id;

	i = -1;
	status->startingTime = getCurrentTime();
	if (status->numberOfTimesMustEat > 0)
		pthread_create(&t_id, NULL, &superviserRoutine, (void *)status);
	while (++i < status->numberOfPhilosophers)
	{
		status->philos[i].pid = fork();
		if (status->philos[i].pid < 0)
			exit(printError("Error forking\n"));
		if (status->philos[i].pid == 0)
		{
			pthread_create(&t_id, NULL, &threadsSupervisor, &status->philos[i]);
			routine(&status->philos[i]);
			exit(1);
		}
		ft_usleep(100);
	}
	while (waitpid(-1, &stat_loc, 0) > 0)
	{
		if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc))
		{
			for (int j = 0; j < status->numberOfPhilosophers; j++)
				kill(status->philos[j].pid, SIGKILL);
		}
	}
	return ;
}