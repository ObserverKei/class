#ifndef __MYTYPE_H__
#define __MYTYPE_H__

extern int StrLen(char *str);


typedef struct StrTypeDef
{
	char str[32];
	int (*Len)(char *);
//	struct StrLen 
//	{
//		int (*Func)(char *);
//	}Len;
}StrType_Str_32;

#endif
