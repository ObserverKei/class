#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char ** environ;

int main(int argc, const char *argv[])
{
	int i = 0;
	char TmpBuf[4096] = {0};

	printf("====================================\n");
//	for (i = 0; environ[i] != NULL; i++)
//	{
//		printf("environ[%d] = %s\n", i, environ[i]);
//	}
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("All environ[%d]: %s\n", i, environ[i]);
	}

	printf("====================================\n");
//	printf("PATH", getenv);
	printf("PATH in environ: %s\n", getenv("PATH"));

	printf("====================================\n");
	getcwd(TmpBuf, sizeof(TmpBuf));
	setenv("PATH", TmpBuf, 1);
	printf("PATH on environ: %s\n", TmpBuf);
	
	printf("====================================\n");

	return 0;
}
