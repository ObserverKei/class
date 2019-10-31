#include "head.h"

int main(int argc, const char *argv[])
{
	int i = 0;

	printf("今天是个好天气!\n");
	printf();
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	return 0;
}

