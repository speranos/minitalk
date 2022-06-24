#include "../minitalk.h"

int	ft_checker(int ac)
{
	if (ac != 3)
	{
		ft_putstr("arg...error !!!\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	bit;
	int	pid;

	i = 0;
	bit = 0;
	if (ft_checker(ac) == 1)
		return (0);
	pid = ft_atoi(av[1]);
	printf("pid ===== %d\n", pid);
	while (av[2][i])
	{
		printf ("i ====== %d\n", i);
		while (bit < 8)
		{
			if ((av[2][i] >> bit & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(500);
		}
		bit = 0;
		i++;
	}
	return (0);
}
