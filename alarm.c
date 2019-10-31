#include "head.h"

void handler(int signo)
{
	printf("SIGALRM信号来了!\n");

	return;
}

int main(int argc, const char *argv[])
{
	int ret = 0;

	signal(SIGALRM, handler);

	ret = alarm(5);
	printf("ret = %d\n", ret);

	sleep(2);
	ret = alarm(10);
	printf("ret = %d\n", ret);

	while (1)
	{
		printf("今天是个好天气!\n");
		sleep(1);
	}

	return 0;
}

