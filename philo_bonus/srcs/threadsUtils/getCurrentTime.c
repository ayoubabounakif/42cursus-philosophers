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

# include "../../includes/philo_bonus.h"

uint64_t	getCurrentTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(uint64_t sleep_time)
{
	uint64_t	start;

	start = getCurrentTime();
	usleep(sleep_time - 20000);
	while (getCurrentTime() - start < sleep_time / 1000)
		continue ;
}