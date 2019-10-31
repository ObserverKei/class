#include "head.h"

#define __RECV_IP__		"192.168.0.168"
#define __RECV_PORT__	50000

struct sock_file_s
{
	int flag;
	char filename[32];
	int size;
	char TmpBuff[1024];
};

int main(int argc, const char *argv[])
{
	if (2 != argc)
	{
		perror("Usage:a.out filename");
		return -1;
	}
	int i = 0;
	int sockfd = 0;
	int Ret = 0;
	struct sockaddr_in sAddrRecvsin;
	struct sock_file_s sockfile;
	int fd = 0;
	int ret = 0;
	
	strcpy(sockfile.filename, argv[1]);

	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
	{
		perror("fail to open");
		return -1;
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockfd)
	{
		perror("fail to socket");
		return -1;
	}

	sAddrRecvsin.sin_family = AF_INET;
	sAddrRecvsin.sin_port = htons(__RECV_PORT__);
	sAddrRecvsin.sin_addr.s_addr = inet_addr(__RECV_IP__);
	//teather 170
	//left 103

	while (0 != (ret = read(fd, sockfile.TmpBuff, sizeof(sockfile.TmpBuff))))
	{
		sockfile.flag = 1;
		sockfile.size = ret;
		Ret = sendto(sockfd, &sockfile, sizeof(struct sock_file_s), 0, (struct sockaddr *)&sAddrRecvsin, sizeof(sAddrRecvsin));
		if (-1 == Ret)
		{
			perror("fail to sendto");
			return -1;
		}
		strcpy(sockfile.TmpBuff, "");
		sockfile.size = 0;
	}

	sockfile.flag = 0;
	Ret = sendto(sockfd, &sockfile, sizeof(struct sock_file_s), 0, (struct sockaddr *)&sAddrRecvsin, sizeof(sAddrRecvsin));
	if (-1 == Ret)
	{
		perror("fail to sendto");
		return -1;
	}

	printf("sendto success\n");

	close(sockfd);
	close(fd);

	return 0;
}
