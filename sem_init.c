#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem_r;
sem_t sem_w;
char TmpBuf[4096] = {0};

void *pthread_puts(void *arg)
{
	while (1)
	{
		sem_wait(&sem_r);
		puts(TmpBuf);
		sem_post(&sem_w);
	}
	return NULL;
}
void *pthread_gets(void *arg)
{
	while (1)
	{
		sem_wait(&sem_w);
		gets(TmpBuf);
		sem_post(&sem_r);
	}
	return NULL;
}



int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[2];
	void *(*pthread_p[])(void *) = {
		pthread_gets,
		pthread_puts
	};


	sem_init(&sem_w, 0, 1);
	sem_init(&sem_r, 0, 0);

	for (i = 0; i < 2; i++)
	{
		pthread_create(&ptid[i], NULL, pthread_p[i], NULL);
	}
	for (i = 0; i < 2; i++)
	{
		pthread_join(ptid[i], NULL);
	}

	sem_destroy(&sem_r);
	sem_destroy(&sem_w);

	return 0;
}
