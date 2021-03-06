/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint64_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:19:02 by aabounak          #+#    #+#             */
/*   Updated: 2019/10/15 20:02:50 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utilsLib.h"

void	ft_putuint64_fd(uint64_t n, int fd)
{
    if (n / 10)
        ft_putuint64_fd(n / 10, fd);
    ft_putchar_fd(n % 10 + '0', fd);
}
