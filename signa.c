#include <stdio.h>
#include "head.h"

pid_t pid;

void handler(int signa)
{
	if (SIGINT == signa)
	{
		if (0 == pid)
		{	
			printf("ded, Im come here!\n");
			kill(getppid(), SIGRTMAX);
		}
	}
	else if (SIGQUIT == signa)
	{
		if (pid > 0)
		{
			printf("son Im come here!!\n");
			kill(pid, SIGRTMAX);
		}
	}
	else if (SIGRTMAX == signa)
	{
		if (pid > 0)
		{
			printf("goto write homework|\n");
		}
		else if (0 == pid)
		{
			printf("alright.\n");
		}
	}

	return;
}

int main(int argc, const char *argv[])
{

	int i = 0;

	signal(SIGQUIT, handler);
	signal(SIGINT, handler);
	signal(SIGTSTP, handler);
	signal(SIGTSTP, handler);
	signal(SIGRTMAX, handler);

	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}
	while(1);

	return 0;
}
