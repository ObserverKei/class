#include <pthread.h>
#include <stdio.h>

void *pthread_1(void *argv)
{
	int i = 0;
	while(i < 100000)
	{
		i++;
		if(i%20 == 0)
		{
			printf("\t pthread_tid:%#x\n", (unsigned int)pthread_self());
		}
	}

	return NULL;
}
void *pthread_2(void *argv)
{
	int i = 0;

	while(i < 100000)
	{
		i++;
		if(i%30 == 0)
		{
			printf("\t pthread_tid:%#x\n", (unsigned int)pthread_self());
		}
	}

	return NULL;
}
void *pthread_3(void *argv)
{
	int i = 0;
	while(i < 100000)
	{
		i++;
		if(i%15 == 0)
		{
			printf("\t pthread_tid:%#x\n", (unsigned int)pthread_self());
		}
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_t ptid[10];
	int ret = 0;
	void *(*ppthread[])(void *) = {
		pthread_1,
		pthread_2,
		pthread_3
	};

	while (i < sizeof(ppthread) / sizeof(ppthread[0]) 
			&& 0 == (ret = pthread_create(&ptid[i], NULL, ppthread[i], NULL)))
	{
		printf("main:tid[%d]: %#x\n", i, (unsigned int)ptid[i]);
		i++;
	}
	if (0 != ret)
	{
		perror("fail to pthread_create");
		return -1;
	}
	pthread_join(ptid[0], NULL);
	for (i = 0; i < sizeof(ppthread) / sizeof(ppthread[0]); i++)
	{
		printf("main:tid[%d]: %#x\n", i, (unsigned int)ptid[i]);
	}
//	sleep(15);
	return 0;
}
