#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	key_t fkey;
	int shmid;
	char *shmaddr = NULL;
	int ret = 0;

	fkey = ftok(".", '8');
	if (-1 == fkey)
	{
		perror("fail to ftok of fkey");
		return -1;
	}
	
	shmid = shmget(fkey, 4096, IPC_CREAT | 0664);
	if (-1 == shmid)
	{
		perror("fail to shmget of shmid");
		return -1;
	}
	printf("shmid = %d\n", shmid);
	shmaddr = (char *)shmat(shmid, NULL, 0);
	if (NULL == shmaddr)
	{
		perror("fail to shmat of shmaddr");
		return -1;
	}
	
#if 1
	while(1)
	{
//		scanf("%s", shmaddr);
#if 0
		if ('q' == *shmaddr)
		{
			break;
		}
#endif
		*shmaddr = getchar();
	}
	sleep(1);
#endif
#if 0  
	while (1)
	{
		gets(shmaddr);
		if (!strcmp(shmaddr, ".quit"))
		{
			break;
		}
	}
#endif

	ret = shmdt(shmaddr);
	if (-1 == ret)
	{
		perror("fail to shmdt");
		return -1;
	}
	ret = shmctl(shmid, IPC_RMID, NULL);
	if (-1 == ret)
	{
		perror("fail to shmctl");
		return -1;
	}



	return 0;
}
