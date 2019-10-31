#include <stdio.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
	int i = 0;
	i = fork();

	if (0 == i)
	{
		puts("child");
	}
	if (i > 0)
	{
		puts("parent");	
	}
	while(1);

	return 0;
}
