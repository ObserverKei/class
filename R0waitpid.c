#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
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
		printf("\t childpid:%d\n", getpid());
		sleep(5);
	}
	if (0 < pid)
	{
		while (0 == (ret = waitpid(pid, &status, WNOHANG)))
		{
			printf("parent: wait for child...\n");
			sleep(1);
		}
		if (WIFEXITED(status))
		{
			printf("parent: child exit status: %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))
		{
			printf("parent: child be kill status: %d\n", WTERMSIG(status));
		}
	}

	return 0;
}
