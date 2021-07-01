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
	uint64_t	time;

	pthread_mutex_lock(&philosopher->status->write);
	time = getCurrentTime() - philosopher->status->startingTime;
	ft_putnbr_fd(time, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd("philosopher ", STDOUT_FILENO);
	ft_putnbr_fd(philosopher->id, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd(messageToPrint, STDOUT_FILENO);

/* 	An upcoming condition, that will be needed for the supervisor */
	if (strcmp(messageToPrint, "died") != 0)
		pthread_mutex_unlock(&philosopher->status->write);
}
