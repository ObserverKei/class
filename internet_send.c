#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, const char *argv[])
{
	int sockfd = 0;
	int Ret = 0;
	struct sockaddr_in RecvAddr;
	char TmpBuff[4096] = {"hello world"};

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockfd)
	{
		perror("fail to socket");
		return -1;
	}

	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(50000);
	RecvAddr.sin_addr.s_addr = inet_addr("192.168.0.177");

	Ret = sendto(sockfd, TmpBuff, strlen(TmpBuff)+1, 0, (struct sockaddr *)&RecvAddr, sizeof(RecvAddr));
	if (-1 == Ret)
	{
		perror("fail to sendto");
		return -1;
	}

	close(sockfd);

	return 0;
}

