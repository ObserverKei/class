#include <stdio.h>
#include "head.h"
#include <errno.h>
#define ERR_EXIT(__errmsg__) do { \
	fprintf(stderr, "[%s:%d:%s]%s:%s\n", __FILE__, __LINE__, __func__, \
										 __errmsg__, strerror(errno)); \
} while (0)


int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	int fd = 0;

	fd = open("fil11e.txt", O_RDONLY);
	if (-1 == fd)
	{
		ERR_EXIT("fail to open");
	}


	return 0;
}
