#include "head.h"

void *thread1(void *arg)
{
	while (1)
	{
		printf("线程1开始执行...\n");
		sleep(1);
	}

	return NULL;
}

void *thread2(void *arg)
{
	while (1)
	{
		printf("线程2开始执行...\n");
		sleep(1);
	}

	return NULL;
}

void *thread3(void *arg)
{
	while (1)
	{
		printf("线程3开始执行...\n");
		sleep(1);
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	pthread_create(&tid3, NULL, thread3, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}

