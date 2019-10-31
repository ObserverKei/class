#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fun1(void)
{
	printf("退出处理函数1...\n");
	return;
}
void fun2(void)
{
	printf("退出处理函数2...\n");
	return;
}
void fun3(void)
{
	printf("退出处理函数3...\n");
	return;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	atexit(fun1);
	atexit(fun2);
	atexit(fun3);
	
//	_exit(0);
//	exit(0);


	printf("hi .");		
	return 0;
}
