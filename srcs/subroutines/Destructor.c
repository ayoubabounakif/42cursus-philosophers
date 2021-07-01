/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:31:54 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 19:32:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

void	Destructor(t_status *status, void (*del)(void *))
{
	int     i;

	i = -1;
	if (status != NULL)
	{
		while (++i < status->numberOfPhilosophers)
			pthread_mutex_destroy(&status->forks[i]);
		if (status->forks)
			(*del)(status->forks);
		if (status->philos)
			(*del)(status->philos);
		pthread_mutex_destroy(&status->write);
	}
	return ;
}
