/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:31:54 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/30 19:32:31 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo_one.h"

void	Destructor(t_status *status, void (*del)(void *))
{
	(void)status;
	(void)del;
/* 	if (status != NULL)
	{
		if (status->forks)
			(*del)(status->forks);
		// if (status->philos)
		// 	(*del)(status->philos);
		if (status)
			(*del)(status);
	} */
	return ;
}
