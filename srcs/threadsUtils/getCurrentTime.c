/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getCurrentTime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:55:51 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 16:56:12 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

uint64_t	getCurrentTime(void)
{
	struct timespec start;
	uint64_t currentTime;

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	currentTime = (start.tv_nsec) / 1000;
	return (currentTime);
}
