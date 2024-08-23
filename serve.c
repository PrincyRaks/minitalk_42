#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handler(int signum)
{
    printf("Received")
	if (signum == SIGUSR1)
		printf("SIGUSR1");
	else if (signum == SIGUSR2)
		printf("SIGUSR2");
}

int	main(void)
{
	pid_t pid = getpid();
	printf("PID : %d \n", pid);

	struct sigaction signal_received;
	signal_received.sa_handler = signal_handler;
	sigemptyset(&signal_received.sa_mask);
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
	{
		// Do some work
	}
	return (0);
}