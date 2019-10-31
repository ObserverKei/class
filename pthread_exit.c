#include <pthread.h>
#include <stdio.h>

void *pthread_1(void *)
{
	printf("pthread_1 start\n");
	sleep(1);
	
	pthread_exit("exit of of pthread_1");

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t ptid;
	int ret = 0;
	void *Tmp = NULL;
	

	ret = pthread_create(&ptid, NULL, pthread_1, NULL);
	pthread_join(ptid, &Tmp);
	puts((char *)Tmp);

	return 0;
}
