#include "head.h"

int main(int argc, const char *argv[])
{
		pid_t pid;
			char *p = NULL;

				p = malloc(32);
					if (NULL == p)
							{
										perror("fail to malloc");
												return -1;
													}

						pid = fork();
							if (-1 == pid)
									{
												perror("fail to fork");
														return -1;
															}
								if (0 == pid)
										{
													strcpy(p, "hello world");
															printf("p = %s\n", p);
																	printf("p = %p\n", p);
																		}
									else if (pid > 0)
											{
														sleep(1);
																printf("p = %s\n", p);
																		printf("p = %p\n", p);
																			}
		if (0 == pid)
		{
			printf("child: %s\n", p);
		}
										return 0;
}

