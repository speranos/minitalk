/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:26:41 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/26 07:29:34 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_checker(int ac, char **av)
{
	int	pid;

	pid = 0;
	if (ac != 3)
	{
		ft_putstr("arg...error !!!\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("arg...error !!!\n");
		return (1);
	}
	return (0);
}

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
	{
		printf ("SERVER IS DONE >>>\n");
		exit(0);
	}
}

void	ft_shift(char **av, int bit, int i, int pid)
{
	while (bit < 8)
	{
		if ((av[2][i] >> bit & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	bit;
	int	pid;

	i = 0;
	bit = 0;
	signal(SIGUSR1, sighandler);
	if (ft_checker(ac, av) == 1)
		return (0);
	pid = ft_atoi(av[1]);
	while (av[2][i] != '\0')
	{
		ft_shift(av, bit, i, pid);
		bit = 0;
		i++;
	}
	ft_shift(av, bit, i, pid);
	pause();
	return (0);
}
