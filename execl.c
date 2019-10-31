#include <stdio.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
	printf("hello world!\n");
	execl("./hello", "./hello", "how", "are", "you", "fine", NULL);
	printf("看到我,execl就失败了!\n");
	printf("how are you!\n");


	return 0;
}
