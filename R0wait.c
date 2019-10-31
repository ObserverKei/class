#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>



int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	int status;

	ret = fork();
	if (-1 == ret)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == ret)
	{
		printf("\tchild pid: %d\n", getpid());
		puts("\tchild sleep...");
		sleep(10);
		exit(100);
	}
	if (0 < ret)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("parent: get child exit status: %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))
		{
			printf("parent: get child be kill status: %d\n", WTERMSIG(status));
		}
	}

	return 0;
}
