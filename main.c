#include "stdio.h"
#include "Cul.h"

int main(int argc, const char *argv[])
{
	int ret = 0;

	ret = add(10, 100);
	printf("add: %d\n", ret);

	return 0;
}
