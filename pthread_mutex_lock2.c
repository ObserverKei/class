#include "head.h"

int num = 0;
pthread_mutex_t lock;

void *thread1(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&lock);
		num = 200;
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

void *thread2(void *arg)
{
	while (1)
	{
		num = 100;
		pthread_mutex_lock(&lock);
		printf("num = %d\n", num);
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

