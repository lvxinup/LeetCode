#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int Check_Sys()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;//�����С�˷���1������Ǵ�˷���0
}

int main()
{
	//int i = 1;
	//char *a = (char *)&i;
	if (Check_Sys())
		printf("С���ֽ���\n");
	else
		printf("����ֽ���\n");

	system("pause");
	return 0;
}