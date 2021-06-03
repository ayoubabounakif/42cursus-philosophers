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

#include "includes/philo_one.h"

t_status	*init(t_status *status, int ac, char **av)
{
	status->number_of_philosophers = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	status->number_of_times_must_eat = ft_atoi(av[5]);

	return (status);
}

int	main(int ac, char **av)
{
	t_status	status;
	
	if (ac < 5 || ac > 6)
			return (ft_exit("Error: Bad arguments number!\nQuitting...\n"));
	else
	{
		init(&status, ac, av);
	}


			// TIME MONITORING FUNCTION (WILL COME BACK TO LAATER)

	// struct timespec start, end;
	// clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	// // DO STUFF
	// clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	// uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

	return (EXIT_SUCCESS);
}
