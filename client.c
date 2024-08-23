#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int main, char **argv)
{
	kill(atoi(argv[1]), SIGUSR1);
	kill(atoi(argv[1]), SIGUSR2);
    return (0);
}
