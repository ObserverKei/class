#include <stdio.h>
#include "mytype.h"

#define Len() Len(Tmp[0].str)

int main(int argc, const char *argv[])
{
	StrType_Str_32 Tmp[] = {
		{"hi", StrLen}
	};
		
	printf("%s : %d\n",Tmp[0].str, Tmp[0].Len());
	return 0;
}
