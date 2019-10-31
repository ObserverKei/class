#include "head.h"

int main(int argc, const char *argv[])
{
	key_t key;
	int shmid = 0;
	char *shmaddr = NULL;

	key = ftok(".", 'a');
	if (-1 == key)
	{
		perror("fail to ftok");
		return -1;
	}
	printf("key = %#x\n", key);

	shmid = shmget(key, 4096, IPC_CREAT | 0664);
	if (-1 == shmid)
	{
		perror("fail to shmget");
		return -1;
	}
	printf("shmid = %d\n", shmid);

	shmaddr = (char *)shmat(shmid, NULL, 0);
	if (NULL == shmaddr)
	{
		perror("fail to shmat");
		return -1;
	}

	gets(shmaddr);

	printf("shmaddr = %s\n", shmaddr);

	shmdt(shmaddr);

	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}

