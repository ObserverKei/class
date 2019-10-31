#include <stdio.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
	execl("/bin/ls", "ls", "-l", NULL);
	puts("fail to execl");

	return 0;
}
