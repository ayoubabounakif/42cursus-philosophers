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
	pthread_t	t_id;

	printf("inside routine %d\n", philosopher->isEating);
	fflush(stdout);
	pthread_create(&t_id, NULL, &threadsSupervisor, &philosopher->status->philos);
	philosopher->lastMeal = getCurrentTime();
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
			sem_wait(status->philos[i].supervisorCounter);
			i++;
		}
		count++;
	}
	sem_wait(status->write);
	i = -1;
	while (++i < status->numberOfPhilosophers)
		kill(status->philos[i].pid, SIGKILL);
	return (NULL);
}

void	runProcesses(t_status *status)
{
	int			i;
	int			j;
	int			stat_loc;
	pthread_t	t_id;

	i = 0;
	status->startingTime = getCurrentTime();
	if (status->numberOfTimesMustEat > 0)
		pthread_create(&t_id, NULL, &superviserRoutine, (void *)status);
	while (i < status->numberOfPhilosophers)
	{
		status->philos[i].lastMeal = getCurrentTime();
		status->philos[i].pid = fork();
		if (status->philos[i].pid < 0)
			exit(printError("Error forking\n"));
		if (status->philos[i].pid == 0)
		{
			// pthread_create(&t_id, NULL, &threadsSupervisor, &status->philos[i]);
			printf("inside childp %d\n", status->philos[i].isEating);
			routine(&status->philos[i]);
			exit(1);
		}
		ft_usleep(100);
		i++; 
	}
	i = -1;
	j = -1;
	while (++i < status->numberOfPhilosophers)
	{
		waitpid(-1, &stat_loc, 0);
		if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc))
		{
			while (++j < status->numberOfPhilosophers)
				kill(status->philos[j].pid, SIGKILL);
		}
	}
	return ;
}
