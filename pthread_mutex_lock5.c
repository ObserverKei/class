#include "head.h"

void *thread(void *arg)
{
	printf("线程开始执行...\n");

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&tid, &attr, thread, NULL);
	pthread_attr_destroy(&attr);

	while (1);

	return 0;
}

