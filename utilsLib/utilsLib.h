/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:20:00 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/03 10:20:01 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define ERR 2

int	    ft_isdigit(int c);
int     ft_strlen(const char *s);
int     ft_putchar_fd(char c, int fd);
int     ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int     ft_atoi(const char *str);
int     printError(char *errorMsg);
int     ft_strcmp(const char *s1, const char *s2);
int	    checkSyntax(char *arg);
#endif