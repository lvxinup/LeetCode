#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int fun()
{
	static int count = 1;
	return ++count;
}

extern int Add(int, int);
extern int g_val;

int main()
{
	//int answer;
	//answer = fun() - fun()*fun();
	//printf("%d\n", answer);

	int a = 10;
	int b = 20;
	int ret = Add(a, b);
	printf("g_val = %d \n", g_val);

	//int arr[3][4] = { 1, 2, 3, 4 };

	system("pause");
	return 0;
}