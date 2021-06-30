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

void	displayChangeOfStatus(char *messageToPrint, t_philo *philosopher)
{
	uint64_t	time;

	pthread_mutex_lock(&philosopher->status->write);
	time = getCurrentTime();
	ft_putnbr_fd(time, STDOUT_FILENO);
	ft_putstr_fd("philosopher ", STDOUT_FILENO);
	ft_putnbr_fd(philosopher->id, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd(messageToPrint, STDOUT_FILENO);

	pthread_mutex_unlock(&philosopher->status->write);
}

void	__eat__(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->status->forks[philosopher->leftFork]);
	ft_putstr_fd("has taken the left fork\n", STDOUT_FILENO);

	pthread_mutex_lock(&philosopher->status->forks[philosopher->rightFork]);
	ft_putstr_fd("has taken the right fork\n", STDOUT_FILENO);

	pthread_mutex_lock(&philosopher->eat);
	ft_putstr_fd("is eating...\n", STDOUT_FILENO);

	// philosopher->lastMeal = getCurrentTime();

	usleep(100);

	ft_putstr_fd("Philosopher finished eating...\n", STDOUT_FILENO);

	pthread_mutex_unlock(&philosopher->status->forks[philosopher->leftFork]);
	pthread_mutex_unlock(&philosopher->status->forks[philosopher->rightFork]);
	pthread_mutex_unlock(&philosopher->eat);
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philosopher = (t_philo *)arg;
	while (1)
	{
		__eat__(philosopher);
		// __sleep__();
		// __think__();
		usleep(100);
	}
	return (EXIT_SUCCESS);
}

t_philo	*philosophersConstructor(t_status *status)
{
	int		i;
	t_philo	*philo;
	
	i = 0;
	philo = (t_philo *)malloc(status->numberOfPhilosophers * sizeof(status->philos));
	while (i < status->numberOfPhilosophers)
	{
		philo[i].id = i + 1;
		philo[i].leftFork = i;
		philo[i].rightFork = (i + 1) % status->numberOfPhilosophers;
		pthread_mutex_init(&philo[i].eat, NULL);
	
		philo[i].status = status;

		i++;
	}
	return (philo);
}

uint64_t	getCurrentTime(void)
{
	struct timespec start;
	uint64_t currentTime;

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	currentTime = (start.tv_sec) * 1000000 + (start.tv_nsec) / 1000;
	return (currentTime);
}

void	runThreads(t_status *status)
{
	pthread_t	threadId;
	int			i;

	i = -1;
	status->currentTime = getCurrentTime();
	pthread_mutex_init(&status->write, NULL);
	while (++i < status->numberOfPhilosophers)
	{
		pthread_create(&threadId, NULL, &routine, &status->philos[i]);
		usleep(150);
	}
	return ;
}

void	mutexConstructor(t_status *status)
{
	int		i;

	i = -1;
	status->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* status->numberOfPhilosophers);
	while (++i < status->numberOfPhilosophers)
		pthread_mutex_init(&status->forks[i], NULL);
	return ;
}

t_status	*Constructor(t_status *status, int ac, char **av)
{
	status->numberOfPhilosophers = ft_atoi(av[1]);
	status->timeToDie = ft_atoi(av[2]);
	status->timeToEat = ft_atoi(av[3]);
	status->timeToSleep = ft_atoi(av[4]);
	if (ac == 6)
		status->numberOfTimesMustEat = ft_atoi(av[5]);
	else
		status->numberOfTimesMustEat = 0;
	status->philos = philosophersConstructor(status);
	return (status);
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
	}
	return (EXIT_SUCCESS);
}
