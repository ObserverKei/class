#include <stdio.h>
#include <pthread.h>

void *pthread_1(void * arg)
{
	int i = 0;
	printf("\n--==--=-==\n-");


	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid1;
	pthread_t ptid2;
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&ptid1, &attr, pthread_1, NULL);
//	pthread_create(&ptid2, NULL, pthread_2, NULL);

	pthread_attr_destroy(&attr);

	sleep(2);

	return 0;
}
