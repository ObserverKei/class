#include "head.h"
#include <errno.h>
#if 0
#include <cstdio>
#include <iostream>
#include <cerrno>
#include <ctypes>
#include <cfctl>
#include <cstat>
#endif

#define ERR_EXIT(__errmsg__) do { \
	fprintf(stderr, "[%s:%d:%s]%s:%s", __FILE__, __LINE__, __func__, \
								 	   __errmsg__, strerror(errno)); \
} while(0)



int main(int argc, const char *argv[])
{
	int fd;

	fd = open("fil1e.txt", O_RDONLY);
	if (-1 == fd)
	{
		ERR_EXIT("fail to open");
	}
	
	return 0;
}

