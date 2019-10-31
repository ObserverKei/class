#include <stdio.h>
#include <pthread.h>

void atexit_1(void)
{
	puts("atexit_1...");
	return;
}

void *pthread_1(void *arg)
{
	printf("pthread_1(%lu) start\n", pthread_self());
	return NULL;
}

void *pthread_2(void *arg)
{
	printf("pthread_2(%lu) start\n", pthread_self());
	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[2];
	void *(*pthread_p[])(void *) = {
		pthread_1,
		pthread_2
	};

	atexit(atexit_1);

	for (i = 0; i < sizeof(pthread_p) / sizeof(pthread_p[0]); i++)
	{
		ret = pthread_create(&ptid[i], NULL, pthread_p[i], NULL);
		if (0 != ret)
		{
			perror("fail to pthread_create");
			return -1;
		}
		else
		{
			printf("pthread_%d(%lu) create success\n", i, ptid[i]);
		}

	}

	ret = pthread_join(ptid[1], NULL);
	if (0 != ret)
	{
		perror("fail to pthread_join");
		return -1;
	}
	else
	{
		printf("pthread_1(%lu) join success\n", ptid[0]);
	}
	ret = pthread_cancel(ptid[2]);
	if (0 != ret)
	{
		perror("fail to pthread_cancel");
		return -1;
	}
	else
	{
		printf("pthread_2(%lu) cancel success\n", ptid[1]);
	}

	sleep(1);

	return 0;
}
