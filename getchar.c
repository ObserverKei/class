#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int cnt_key = 0;
	int i = 0;
	char readkey[4] = {0};
	char key_up[4] = {27, 91, 65, 0};
	char key_down[4] = {27, 91, 66, 0};
	char key_left[4] = {27, 91, 68, 0};
	char key_right[4] = {27, 91, 67, 0};
	char key_enter[4] = {10, 0, 0, 0};
	char key_esc[4] = {27, 0, 0, 0};
	while (1)
	{
//		readkey[cnt_key++] = getchar();
		strcpy(readkey, "");
		fgets(readkey, sizeof(readkey), stdin);
	//	system("clear");
#if 0
		while (i < 4)
		{
			printf("\t%d \n", readkey[i]);
			i++;
		}
#endif
		if ( ! strcmp(readkey, key_up))
		{
			puts("Up");
		}
		else if ( ! strncmp(readkey, key_down, sizeof(readkey)))
		{
			puts("Down");
		}
		else if ( ! strncmp(readkey, key_left, sizeof(readkey)))
		{
			puts("Left");
		}
		else if ( ! strncmp(readkey, key_right, sizeof(readkey)))
		{
			puts("Right");
		}
		else if ( ! strncmp(readkey, key_enter, sizeof(readkey)))
		{
			puts("Enter");
		}
		else if ( ! strncmp(readkey, key_esc, sizeof(readkey)))
		{
			puts("Esc");
		}
	}

	return 0;
}
