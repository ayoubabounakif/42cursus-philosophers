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

# include "../../includes/philo_bonus.h"

void	displayChangeOfStatus(char *messageToPrint, t_philo *philosopher)
{
	uint64_t	timeDiff;

	sem_wait(philosopher->status->write);
	timeDiff = getCurrentTime() - philosopher->status->startingTime;
	// printf("%llu philosopher %d %s\n", timeDiff, philosopher->id, messageToPrint);
	ft_putuint64_fd(timeDiff, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putuint64_fd(philosopher->id, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putstr_fd(messageToPrint, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);

/* 	An upcoming condition, that will be needed for the supervisor */
	if (ft_strcmp(messageToPrint, "died") != 0)
		sem_post(philosopher->status->write);
}
