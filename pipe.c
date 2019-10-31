#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



int main(int argc, const char *argv[])
{
	int i = 0;
	int fd[2];
	int ret = 0;
	pid_t pid = 0;
	char TmpBuf[1024] = {0};
	
	ret = pipe(fd);
	if (-1 == ret)
	{
		perror("fail to pipe");
		return -1;
	}
	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == pid)
	{
		sprintf(TmpBuf, "hi~\n");
		sleep(3);
		write(fd[1], TmpBuf, sizeof(TmpBuf));
	}
	if (pid > 0)
	{
		read(fd[0], TmpBuf, sizeof(TmpBuf));
		printf("%s", TmpBuf);
	}

	return 0;
}
