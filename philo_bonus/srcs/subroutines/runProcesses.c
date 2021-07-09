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

void	routine(t_philo	*philosopher)
{
	// t_philo		*tmp;
	// pthread_t	t_id;

	// tmp = philosopher;
	// printf("philo id : %d || isEating before supervisor %d || %p\n", philosopher->id, philosopher->isEating, &philosopher->isEating);
	// pthread_create(&t_id, NULL, &threadsSupervisor, (void *)philosopher);
	// philosopher->lastMeal = getCurrentTime();
	while (420)
	{
		__eat__(philosopher);
		__sleep__(philosopher);
		__think__(philosopher);
	}
}

void	*superviserRoutine(void *arg)
{
	t_status	*status;
	int			count;
	int			i;

	status = (t_status *)arg;
	count = 0;
	while (count < status->numberOfTimesMustEat)
	{
		i = 0;
		while (i < status->numberOfPhilosophers)
		{
			sem_wait(status->supervisorCounter);
			i++;
		}
		count++;
	}
	sem_wait(status->write);
	i = -1;
	while (++i < status->numberOfPhilosophers)
		kill(status->philos[i].pid, SIGKILL);
	return (EXIT_SUCCESS);
}

void	runProcesses(t_status *status)
{
	int			i;
	int			j;
	int			stat_loc;
	pthread_t	t_id;

	if (status->numberOfTimesMustEat > 0)
		pthread_create(&t_id, NULL, &superviserRoutine, (void *)status);
	status->startingTime = getCurrentTime();
	i = 0;
	while (i < status->numberOfPhilosophers)
	{
		status->philos[i].lastMeal = getCurrentTime();
		status->philos[i].pid = fork();
		if (status->philos[i].pid < 0)
			exit(printError("Error forking\n"));
		if (status->philos[i].pid == 0)
		{
			pthread_create(&t_id, NULL, &threadsSupervisor, (void *)(&status->philos[i]));
			routine(&status->philos[i]);
			exit(1);
		}
		i++;
		usleep(100);
	}
	i = -1;
	while (++i < status->numberOfPhilosophers)
	{
		waitpid(-1, &stat_loc, 0);
		if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc))
			break ;
	}
	j = -1;
	while (++j < status->numberOfPhilosophers)
		kill(status->philos[j].pid, SIGKILL);
	exit(420);
}
