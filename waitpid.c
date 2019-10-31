#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	pid_t ret = 0;
	pid_t pid;
	int status;

	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == pid)
	{
		printf("\tchild pid: %d start\n", getpid());
		printf("\tchild pid: %d start\n", getpid());
		sleep(10);
	}
	else if (pid > 0)
	{
		printf("parent start\n");
		while (0 == (ret = waitpid(pid, &status, WNOHANG)))
		{
			printf("miao~\n");
//			printf("miao~miao~\n");
//			printf("miao!\n");
			sleep(1);
		}
		if (WIFEXITED(status))
		{
			printf("parent: child end status: %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))
		{
			printf("parent: child be kill status: %d\n", WTERMSIG(status));
		}
	}


	
	return 0;
}
