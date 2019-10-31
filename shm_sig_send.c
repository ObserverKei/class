#include "head.h"

int main(int argc, const char *argv[])
{
	key_t key = 0;
	int shmid = 0;
	char *shmaddr = NULL;

	key = ftok(".", 'a');
	if (-1 == key)
	{
		perror("fail to ftok");
		return -1;
	}

	shmid = shmget(key, 4096, IPC_CREAT | 0664);
	if (-1 == shmid)
	{
		perror("fail to shmget");
		return -1;
	}

	shmaddr = (char *)shmat(shmid, NULL, 0);
	if (NULL == shmaddr)
	{
		perror("fail to shmat");
		return -1;
	}

	while (1)
	{
		gets(shmaddr);
		if (!strcmp(shmaddr, ".quit"))
		{
			break;
		}
	}

	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
