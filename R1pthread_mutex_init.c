#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int i = 0;
int a = 0;
int b = 0;

void *pthread_1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		printf("i = %d\n", i);
		i++;
		a = i;
		b = i;
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}
void *pthread_2(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		printf("a=%d,b=%d\n", a, b);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_t ptid1;
	pthread_t ptid2;
	pthread_attr_t attr;

//	pthread_attr_init(&attr);
//	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_mutex_init(&lock, NULL);

	pthread_create(&ptid1, NULL, pthread_1, NULL);
	pthread_create(&ptid2, NULL, pthread_2, NULL);

	pthread_join(ptid1, NULL);
	pthread_join(ptid2, NULL);

	pthread_mutex_destroy(&lock);
//	pthread_attr_destroy(&attr);
	


	return 0;
}
