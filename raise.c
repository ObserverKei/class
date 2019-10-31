#include "head.h"
#include <signal.h>

void handler(int signa)
{
	if (SIGINT == signa)	
	{
		puts("SIGINT!!!!!");
		sleep(1);
		raise(SIGINT);
	}
	if (SIGALRM == signa)
	{
		puts("SIGALRM!!!!!!!");
		alarm(1);
	}

	return ;
}

int main(int argc, const char *argv[])
{
	int i = 0;

	signal(SIGINT, handler);
	signal(SIGALRM, handler);
		
	i = alarm(3);
	printf("i = %d\n", i);
	sleep(1);
	i = alarm(5);
	printf("i = %d\n", i);
	
	while(1);
	return 0;
}
