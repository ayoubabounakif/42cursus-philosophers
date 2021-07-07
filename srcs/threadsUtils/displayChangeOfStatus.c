/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayChangeOfStatus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:56:23 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:56:36 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

void	displayChangeOfStatus(char *messageToPrint, t_philo *philosopher)
{
	uint64_t	timeDiff;

	pthread_mutex_lock(&(philosopher->status->write));
	timeDiff = getCurrentTime() - philosopher->status->startingTime;
	printf("%llu philosopher %d %s\n", timeDiff, philosopher->id, messageToPrint);

/* 	An upcoming condition, that will be needed for the supervisor */
	if (ft_strcmp(messageToPrint, "died") != 0)
		pthread_mutex_unlock(&(philosopher->status->write));
}
