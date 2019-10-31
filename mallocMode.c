#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define IDNum_10 10
sem_t sem_box;
pthread_mutex_t lock;
struct Box_S
{
	int flag;
	char str[1024];
};
struct Box_S box[] = {
	{1, "box1"},
	{1, "box2"},
	{1, "box3"},
};

char *mymalloc(int Len, struct Box_S *pbox)
{
	int i = 0;
	
	sem_wait(&sem_box);
	for (i = 0; i < Len; i++)
	{
		pthread_mutex_lock(&lock);
		if (pbox[i].flag > 0)
		{
			pbox[i].flag = 0;
			pthread_mutex_unlock(&lock);
			
			return pbox[i].str;
		}
		else
		{
			pthread_mutex_unlock(&lock);			
		}
	}

	return NULL;
}

void myfree(char *Tmpstr)
{
	int i = 0;
	for (i = 0; i < sizeof(box) / sizeof(box[0]); i++)
	{
		if ( ! strcmp(Tmpstr, box[i].str))
		{
			box[i].flag = 1;
//			memset(pbox->str, 0, sizeof(pbox->str) / sizeof(pbox->str[0]));	
		}
	}

	sem_post(&sem_box);

	return ;
}

void *pthread_p(void *arg)
{
	int i = 0;
	char *pTmpstr;

	while (1)
	{
		printf("id[%d] start apply for box\n", *(int *)arg);

		if (NULL != (pTmpstr = mymalloc(sizeof(box) / sizeof(box[0]), box)))
		{
//			gets(pTmpbox->str);
			printf("\tid[%d] use box:%s\n", *(int *)arg, pTmpstr);
			sleep(rand()%10 + 1);
			printf("\t\tid[%d] lose box:%s\n", *(int *)arg, pTmpstr);
			myfree(pTmpstr);
			break;
		}
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[IDNum_10];
	int id[IDNum_10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	srand(time(NULL));
	sem_init(&sem_box, 0, sizeof(box) / sizeof(box[0]));
	pthread_mutex_init(&lock, NULL);

	for (i = 0; i < IDNum_10; i++)
	{
		pthread_create(&ptid[i], NULL, pthread_p, &id[i]);
	}
	for (i = 0; i < IDNum_10; i++)
	{
		pthread_join(ptid[i], NULL);
	}


	pthread_mutex_destroy(&lock);
	sem_destroy(&sem_box);

	return 0;
}
