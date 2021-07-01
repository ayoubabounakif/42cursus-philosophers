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
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
