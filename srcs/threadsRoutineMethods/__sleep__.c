/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sleep__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:51:28 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:51:43 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

void	__sleep__(t_philo *philosopher)
{
	uint64_t time;

	displayChangeOfStatus("is sleeping\n", philosopher);
	time = getCurrentTime();
	usleep(philosopher->status->timeToSleep * 1000 - 10000);
	while (getCurrentTime() - time < philosopher->status->timeToSleep);
	return ;
}
