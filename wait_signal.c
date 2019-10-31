#include "head.h"

int main(int argc, const char *argv[])
{
	pid_t pid;
	pid_t ret;
//	int status;
	int status;

	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}

	if (0 == pid)
	{
		printf("子进程(%d)开始执行!\n", getpid());
		sleep(15);
		exit(100);
	}
	else if (pid > 0)
	{

		printf("父进程开始执行!\n");
		ret = wait(&status);
//		ret = wait(&status);
		printf("回收到子进程(%d)空间!\n", ret);
		if (WIFEXITED(status))
		{
			printf("子进程退出值为%d\n", WEXITSTATUS(status));
			
		}
		else if (WIFSIGNALED(status))
		{		
			printf("子进程被%d号信号杀死!\n", WTERMSIG(status));
		}
#if 0
		if (WIFEXITED(status))
		{
			printf("子进程退出值为%d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			printf("子进程被%d号信号杀死!\n", WTERMSIG(status));
		}
#endif
	}

	return 0;
}

