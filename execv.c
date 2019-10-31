#include <stdio.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
	int i = 0;
	char *execargv[] = {
		"ls",
		"-l"
	};
	execvp("ls", execargv);
//	execv("./hello", execargv);
	puts("error of execv");

	return 0;
}
