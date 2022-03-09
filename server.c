
#include "header.h"

void check_bit(int sig)
{
	if (sig == SIGUSR1)
    	write(1, "sigusr1\n", 20);
	if (sig == SIGINT)
    	write(1, "siguser 2,\n", 20);
}

int main()
{
	signal(SIGUSR1, check_bit);
	signal(SIGUSR2, check_bit);
	printf("%d \n"  , getpid());
	while (1)
	{
		pause();
	}
	
	return 0;
}
