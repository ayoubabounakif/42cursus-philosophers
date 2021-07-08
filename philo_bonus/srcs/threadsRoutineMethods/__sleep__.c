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

# include "../../includes/philo_bonus.h"

void	__sleep__(t_philo *philosopher)
{
	ft_usleep(philosopher->status->timeToSleep * 1000);
	return ;
}
