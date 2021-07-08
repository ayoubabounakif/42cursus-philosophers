/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getCurrentTime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:55:51 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/05 10:32:19 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

uint64_t	getCurrentTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int sleep_time)
{
	uint64_t	start;
	uint64_t	time_diff;

	start = getCurrentTime() * 1000;
	while (1)
	{
		time_diff = sleep_time - (getCurrentTime() * 1000 - start);
		if (time_diff < 50)
		{
			usleep(time_diff);
			break ;
		}
		if (time_diff > (uint64_t)sleep_time)
			break ;
		usleep(50);
	}
}