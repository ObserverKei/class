#include "head.h"

struct sock_file_s
{
	char filename[32];
	int size;
	char TmpBuff[4096];
};

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	struct sockaddr_in sAddrRecvsin;
	struct sock_file_s sockfile;
	int fd;
	int sockfd;
	int Ret = 0;

	sAddrRecvsin.sin_family = AF_INET;
	sAddrRecvsin.sin_port = htons(50000);
	sAddrRecvsin.sin_addr.s_addr = inet_addr("192.168.174");

	Ret = bind(sockfd, (struct sockaddr *)&sAddrRecvsin, sizeof(sAddrRecvsin));
	if (-1 == Ret)
	{
		perror("fail to bind");
		return -1;
	}
	
	Ret = recvfrom(sockfd, &sockfile, sizeof(sockfile), 0, NULL, NULL);
	if (-1 == Ret)
	{
		perror("fail to recvfrom");
		return -1;
	}
	
	fd = open(sockfile.filename, O_WRONLY | O_CREAT | 0664);
	if (-1 == fd)
	{
		perror("fail to open");
		return -1;
	}
	while (0 != (ret = write(fd, sockfile.TmpBuff, sockfile.size)))
	{
		printf("recv success\n");
	}

	close(fd);
	close(sockfd);

	return 0;
}
