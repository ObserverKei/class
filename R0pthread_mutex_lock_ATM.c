#include <stdio.h>
#include <pthread.h>

int ATM = 3;
pthread_mutex_t lock;

void *pthread_ATM(void *arg)
{
	int i = 0;
	
	while (1)
	{
		pthread_mutex_lock(&lock);
		if (ATM > 0)
		{
			ATM--;			
			printf("ATM stat:%d\n", ATM);
			pthread_mutex_unlock(&lock);
			printf("%lu pthread in ATM\n", pthread_self());
			sleep(1);
			printf("\t%lu pthread out ATM\n", pthread_self());
			ATM++;
			break;
		}
		else
		{
			pthread_mutex_unlock(&lock);
		}
	}


	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[10];
	
	pthread_mutex_init(&lock, NULL);
	for (i = 0; i < 10; i++)
	{
		pthread_create(&ptid[i], NULL, pthread_ATM, NULL);
	}
	for (i = 0; i < 10; i++)
	{
		pthread_join(ptid[i], NULL);
	}
	pthread_mutex_destroy(&lock);

	return 0;
}
