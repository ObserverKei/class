#include <stdio.h>
#include <pthread.h>

void atexit_1(void)
{
	printf("exit_1 start...\n");
	
	return ;
}

void *pthread_1(void *arg)
{
	printf("pthread_1(%lu) start.", pthread_self());
	
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
		printf("pthread_1(%lu) create seccess\n", ptid);
	}
	
	ret = pthread_cancel(ptid);
	if (0 != ret)
	{
		perror("fail to pthread_cancel");
		return -1;
	}
	ret = pthread_join(ptid, NULL);
	if (0 != ret)
	{
		perror("fail to pthread_join");
		return -1;
	}
	
	sleep(0);


	return 0;
}
