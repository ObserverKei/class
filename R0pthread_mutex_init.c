#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *pthread_1(void *arg)
{

	puts("s=-=-=--");
		
	return NULL;
}



int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_attr_t attr;
	pthread_t ptid;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&ptid, &attr, pthread_1, NULL);
	pthread_attr_destroy(&attr);

	sleep(1);
	return 0;
}
