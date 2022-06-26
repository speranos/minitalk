/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:21:20 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/26 07:24:53 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	get_pid(int siguser, siginfo_t *info, void *cont)
{
	int			signalpid;
	static char	c;
	static int	b;

	(void)cont;
	signalpid = info->si_pid;
	if (siguser == SIGUSR1)
	{
		c = c | (1 << b);
		b++;
	}		
	else if (siguser == SIGUSR2)
	{
		c = c | (0 << b);
		b++;
	}
	if (b == 8)
	{
		if (c == '\0')
			kill(signalpid, SIGUSR1);
		ft_putchar(c);
		c = '\0';
		b = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	ft_printf ("pid === %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
