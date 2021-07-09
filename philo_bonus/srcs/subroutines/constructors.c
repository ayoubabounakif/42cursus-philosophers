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
	sem_unlink("forks");
	status->forks = sem_open("forks", O_CREAT, 0644, status->numberOfPhilosophers);
	sem_unlink("write");
	status->write = sem_open("write", O_CREAT, 0644, 1);
	sem_unlink("lock me when eating");
	status->eat = sem_open("lock me when eating", O_CREAT, 0644, status->numberOfPhilosophers / 2);
	return ;
}

t_philo	*philosophersConstructor(t_status *status)
{
	int		i;
	t_philo	*philo;
	
	i = 0;
	philo = (t_philo *)malloc(status->numberOfPhilosophers * sizeof(t_philo));
	while (i < status->numberOfPhilosophers)
	{
		philo[i].id = i + 1;
		philo[i].isEating = 0;
		philo[i].status = status;
		i++;
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
	sem_unlink("eating counter semaphore");
	status->supervisorCounter = sem_open("eating counter semaphore", O_CREAT, 0644, 0);
	status->philos = philosophersConstructor(status);
	return (EXIT_SUCCESS);
}
