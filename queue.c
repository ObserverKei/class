#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct queue_def_s
{
	char list[50][50];
	int head;
	int tail;
};

void *Water(void *arg);
void *Dest(void *arg);

struct queue_def_s queue = {0};
sem_t sem_desk;

void *Dest(void *arg)
{
	srand(time(NULL));	

	printf("%s eating...\n", (char *)arg);
	sleep(rand()%10 + 1);
	printf("\t%s leave...\n", (char *)arg);
	sem_post(&sem_desk);

	return NULL;
}

void *Water(void *arg)
{
	pthread_attr_t attr;
	pthread_t ptid;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	while (1)
	{
		sem_wait(&sem_desk);
		if (queue.head != queue.tail)
		{
			pthread_create(&ptid, &attr, Dest, queue.list[queue.head]);
			queue.head++;
		}
		else
		{
			sem_post(&sem_desk);
		}
	}


	pthread_attr_destroy(&attr);

	return NULL;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_t ptid;

	sem_init(&sem_desk, 0, 3);

	pthread_create(&ptid, NULL, Water, NULL);

	while (1)
	{
		gets(queue.list[queue.tail]);
		queue.tail++;
	}

	pthread_join(ptid, NULL);
	sem_destroy(&sem_desk);


	return 0;
}
