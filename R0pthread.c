#include <pthread.h>
#include <string.h>
#include <stdio.h>

void atexit_1(void)
{
	puts("exit setting1...");
	return;
}
	

void *pthread_1(void *i)
{
	puts("pthread_1 start");
	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_t ptid;
	int ret = 0;

	atexit(atexit_1);
	ret = pthread_create(&ptid, NULL, pthread_1, NULL);
	if (0 != ret)
	{
		perror("fail to pthread_create");
		return -1;
	}
	else
	{
		puts("create success");
	}
	ret = pthread_join(ptid, NULL);
	if (0 != ret)
	{
		perror("fail to pthread_join");
		return -1;
	}
	else
	{
		puts("join success");
	}


	sleep(1);
	
	return 0;
}
