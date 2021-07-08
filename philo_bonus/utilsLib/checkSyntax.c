/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkSyntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:10:23 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/07 15:10:44 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utilsLib.h"

int	checkSyntax(char *arg)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (ERR);
	}
	return (EXIT_SUCCESS);
}
