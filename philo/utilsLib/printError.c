/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printError.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:56:35 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/03 09:56:35 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utilsLib.h"

int	printError(char *errorMsg)
{
	ft_putstr_fd(errorMsg, STDERR_FILENO);
	return (EXIT_FAILURE);
}
