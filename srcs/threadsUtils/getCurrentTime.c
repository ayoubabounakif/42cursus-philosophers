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

# include "../../includes/philo_one.h"

uint64_t	getCurrentTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// void	ft_usleep(int timeToSleep)
// {
// 	uint64_t	start;
// 	uint64_t	timeDiff;

// 	start = getCurrentTime();
// 	while (1)
// 	{
// 		timeDiff = timeToSleep - (getCurrentTime() - start);
// 		if (timeDiff < 0)
// 			break ;
// 		if (timeDiff < 50)
// 		{
// 			usleep(timeDiff);
// 			break ;
// 		}
// 		if (timeDiff > (uint64_t)timeToSleep)
// 			break ;
// 		usleep(50);
// 	}
// }
