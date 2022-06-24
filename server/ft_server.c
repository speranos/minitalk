#include "../minitalk.h"

void	sighandler(int siguser)
{
	if (siguser == SIGUSR1)
		printf ("ft\n");
	else
		printf ("gt\n");
}

int	main()
{
	//struct sigaction sa;
	//sa.sa_handler = &sighandler;
	
	printf ("pid === %d\n", getpid());

	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	pause();
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR1, &sa, NULL);
	
}
