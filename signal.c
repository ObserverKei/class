#include <stdio.h>
#include <signal.h>

void handler(int arg)
{

	printf("不理你\n");

	return ;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	void (*ret)(int) = NULL;

	ret = signal(SIGINT, handler);
	if (SIG_ERR == ret)
	{
		perror("fail to signal");
		return -1;
	}

	while(1);

	return 0;
}
