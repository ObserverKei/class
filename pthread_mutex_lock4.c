#include "head.h"

void *thread(void *arg)
{
	int *ptmp = arg;

	*ptmp = 200;
	printf("次线程:Num = %d\n", *ptmp);

	return NULL;
}

void *thread1(void *arg)
{
	char *ptmp = arg;

	strcpy(ptmp, "hello world");

	printf("次线程:tmpbuff = %s\n", ptmp);

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t tid;
	int Num = 100;
	char tmpbuff[64] = {0};
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

//	pthread_create(&tid, NULL, thread, &Num);
	pthread_create(&tid, &attr, thread1, tmpbuff);

//	pthread_join(tid, NULL);
//	printf("主线程:Num = %d\n", Num);
	printf("主线程:tmpbuff = %s\n", tmpbuff);

	while (1);

	return 0;
}

