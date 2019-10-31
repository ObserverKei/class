#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	char Tmpbuf[1024];

	if (2 == argc)
	{
		strcpy(Tmpbuf, argv[1]);
		printf("dir: %s\n", getwd(Tmpbuf));
		/* code */
	}
	
	return 0;
}
