#include "head.h"

struct student 
{
	char name[32];
	char sex;
	int age;
	int score;
};

void *thread1(void *arg)
{	
	struct student *p = arg;

	printf("请输入姓名:\n");
	gets(p->name);
	printf("请输入性别:\n");
	p->sex = getchar();
	printf("请输入年龄:\n");
	scanf("%d", &p->age);
	printf("请输入成绩:\n");
	scanf("%d", &p->score);

	return NULL;
}

void *thread2(void *arg)
{
	struct student *p = arg;

	printf("姓名:%s\n", p->name);
	printf("性别:%c\n", p->sex);
	printf("年龄:%d\n", p->age);
	printf("成绩:%d\n", p->score);

	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t tid1;
	pthread_t tid2;
	struct student s;

	pthread_create(&tid1, NULL, thread1, &s);

	pthread_create(&tid2, NULL, thread2, &s);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

