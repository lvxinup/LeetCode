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
	return un.c;//如果是小端返回1，如果是大端返回0
}

int main()
{
	//int i = 1;
	//char *a = (char *)&i;
	if (Check_Sys())
		printf("小端字节序\n");
	else
		printf("大端字节序\n");

	system("pause");
	return 0;
}