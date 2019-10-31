#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void func1(void)
{
	printf("atexit setmode 1...\n");
	return;
}
void func2(void)
{
	printf("atexit setmode 2...\n");
	return;
}
void func3(void)
{
	printf("atexit setmode 3...\n");
	return;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	int Ret = 0;
	
	atexit(func1);
	atexit(func2);
	atexit(func3);

	puts("system exit...");
	
	sleep(1);

	return 0;
}
