#include <pthread.h>
#include <stdio.h>
#include <string.h>


void *pthread_1(void *i)
{
	puts("start ptid_1");
	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	pthread_t ptid;
	
	pthread_create(&ptid, NULL, pthread_1,NULL);
	
	sleep(1);
		
	return 0;
}
