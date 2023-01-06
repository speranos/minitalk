/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:31:55 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/26 07:33:13 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_atoi(const char *str);

#endif
