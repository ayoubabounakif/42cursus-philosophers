/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:47:46 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:48:42 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_bonus.h"

void	semaphoreConstructor(t_status *status)
{
	int		i;

	i = -1;
	sem_unlink("forks");
	status->forks = sem_open("forks", O_CREAT, 0644, status->numberOfPhilosophers);
	sem_unlink("write");
	status->write = sem_open("write", O_CREAT, 0644, 1);
	sem_unlink("eat");
	status->eat = sem_open("eat", O_CREAT, 0644, 1);
	while (++i < status->numberOfPhilosophers)
		status->philos[i].lastMeal = getCurrentTime();
	return ;
}


t_philo	*philosophersConstructor(t_status *status)
{
	int		i;
	t_philo	*philo;
	
	i = -1;
	philo = (t_philo *)malloc(status->numberOfPhilosophers * sizeof(t_philo));
	while (++i < status->numberOfPhilosophers)
	{
		philo[i].id = i + 1;
		philo[i].leftFork = i;
		philo[i].rightFork = (i + 1) % status->numberOfPhilosophers;
		philo[i].numberOfTimesAte = 0;
		philo[i].isEating = 0;
		sem_unlink("Eating semaphore");
		philo[i].eat = sem_open("Eating semaphore", O_CREAT, 0644, 1);
		philo[i].status = status;
	}
	return (philo);
}

int	Constructor(t_status *status, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (checkSyntax(av[i]) == ERR)
			return (printError("Error: Bad arguments syntax\n"));
	}
	status->numberOfPhilosophers = ft_atoi(av[1]);
	status->timeToDie = ft_atoi(av[2]);
	status->timeToEat = ft_atoi(av[3]);
	status->timeToSleep = ft_atoi(av[4]);
	if (ac == 6)
		status->numberOfTimesMustEat = ft_atoi(av[5]);     
	else
		status->numberOfTimesMustEat = 0;
	status->supervisorCounter = 0;
	status->philos = philosophersConstructor(status);
	return (EXIT_SUCCESS);
}
