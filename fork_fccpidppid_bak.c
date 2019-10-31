#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int d = 0;
	int *pd = &d;
	char *pstr = malloc(32);

	unsigned long long int i = 0;
	int Ret_fork_child_1 = 0;
	printf("Parent_Pid:%d\n", getpid());
	Ret_fork_child_1 = fork();
	 // if (0 == Ret_fork_child_1)  
	if (0 == Ret_fork_child_1)
	{
		*pd = 100;
		printf("\tChild: childPid_1\n");
		printf("\tPid:%d, PPid:%d\n", getpid(), getppid());
		printf("childPid_1 : *pd:%d\n", *pd);
		strcpy(pstr, "how are you");
	}
	else
	{

//		sleep(1);
		while (i < 1000000)
		{
			i++;
		}
		printf("d = %d\n", d);
		printf("Parent: %s\n", pstr);
		printf("Parent: childPid_1_pid:%d\n", Ret_fork_child_1);
		Ret_fork_child_1 = fork();
		if (Ret_fork_child_1 > 0)
		{	
			printf("Parent: childPid_2_pid:%d\n", Ret_fork_child_1);
		}
		if (0 == Ret_fork_child_1)
		{
			printf("\tChild: childPid_2\n");
			printf("\tPid:%d, PPid:%d\n", getpid(), getppid());
		}
	}
	sleep(1);
//	while(1);
	
	return 0;
}
