#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
	int Ret_fork_child_1 = 0;
	int Ret_fork_child_2 = 0;
	printf("Parent_Pid:%d\n", getpid());
	Ret_fork_child_1 = fork();
	if (Ret_fork_child_1 > 0)
	{
		printf("Parent: childPid_1_pid:%d\n", Ret_fork_child_1);
		Ret_fork_child_2 = fork();
		if (Ret_fork_child_2 > 0)
		{	
			printf("Parent: childPid_2_pid:%d\n", Ret_fork_child_2);
		}
		if (0 == Ret_fork_child_2)
		{
			printf("Child: childPid_2\n");
			printf("Pid:%d, PPid:%d\n", getpid(), getppid());
		}
	}
	else // if (0 == Ret_fork_child_1)  
	{
		printf("Child: childPid_1\n");
		printf("Pid:%d, PPid:%d\n", getpid(), getppid());
	}
	while(1);
	
	return 0;
}
