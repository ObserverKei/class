#include <stdio.h>
//#include <attributes.h>
//#include <semaphore.h>
#include <pthread.h>
#include <time.h>

void *pthread_1(void *arg)
{
	while (1)
	{
		sleep(rand()%10 + 1);
		puts("end");
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_attr_t attr;
	pthread_t ptid;
	
	srand(time(NULL));

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&ptid, &attr, pthread_1, NULL);
	pthread_attr_destroy(&attr);
	pthread_join(ptid, NULL);
	sleep(15);

	return 0;
}
