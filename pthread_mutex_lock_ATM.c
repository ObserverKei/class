#include "head.h"

int ATM = 3;
pthread_mutex_t lock;

void *pthread_ATM(void *arg)
{
	while(1)
	{

		pthread_mutex_lock(&lock);
		if (ATM > 0)
		{
			printf("ATM-- stat:%d\n", ATM);
			//			printf(" IN ATM stat:%d\n", ATM);
			ATM--;
			pthread_mutex_unlock(&lock);
			printf("ATM stat:%d", ATM);
			//			printf("OUT ATM stat:%d\n", ATM);
			printf("%lu pthread in ATM\n", pthread_self());
			sleep(rand() % 10 +1);
			printf("\t%lu pthread out ATM\n", pthread_self());
			printf("ATM++ stat:%d\n", ATM);
			ATM++;
			break;
		}
		else
		{
			pthread_mutex_unlock(&lock);
		}
	}
	puts("");

	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[100];

	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		//		pthread_mutex_lock(&lock);
		pthread_create(&ptid[i], NULL, pthread_ATM, NULL);
		//		pthread_mutex_unlock(&lock);
	}

	for (i = 0; i < 100; i++)
	{
		pthread_join(ptid[i], NULL);
	}

	return 0;
}

