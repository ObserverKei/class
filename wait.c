#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

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
		printf("childpid: %d\n", getpid());
		puts("\tchild sleep...");
		sleep(15);
		exit(100);
		
	}
	if (ret > 0)
	{
		printf("parent: creat complete\n");
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("parent: child over status: %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))
		{
			printf("printf: child be kill status: %d\n", WTERMSIG(status));
		}
		
	}


	return 0;
}
