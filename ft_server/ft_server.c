#include "../minitalk.h"

void	sighandler(int siguser)
{
	static char c;
	static int	b;
	if (siguser == SIGUSR1)
	{
		c = c | (1 << b);
		// c = c << b | 1;
		b++;
	}		
	else if (siguser == SIGUSR2)
	{
		c = c | (0 << b);
		// c = c << b | 0;
		b++;
	}
	if (b == 8)
	{
		ft_putchar(c);
		c = '\0';
		b = 0;
	}
}

int	main()
{
	// struct sigaction sa;
	// sa.sa_handler = &sighandler;
	
	printf ("pid === %d\n", getpid());

	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
	
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR1, &sa, NULL);
	// while (1)
	// 	pause();
	
}
