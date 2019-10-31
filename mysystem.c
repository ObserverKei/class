#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct CmdCode
{
	char name[32];
	int *()();
};


int CommandAnalyze(char *len)
{
	int i = 0;
	return 0;
}

int MySystem(int , const char *arg)
{
	int i = 0;
	char *pTmp[10] = {NULL};
	pid_t pid;
	int status;

	pTmp[i] = strtok(Str, " ");
	i++;

	while (NULL != (pTmp[i] = strtok(NULL," ")))
	{
		i++;
	}
	pid = fork();
	if (-1 == pid)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == pid)
	{
		execvp(pTmp[0], pTmp);
	}
	else if (pid > 0)
	{
		waitpid(0, &status, 0);
	}
	return status;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	char Tmp[4096] = {0};
	char *pTmp = "..";
	while (1)
	{
		printf("[Linux@Ubuntu:%s]$", getcwd(Tmp, sizeof(Tmp)));
		gets(Tmp);

	}

	return 0;
}
