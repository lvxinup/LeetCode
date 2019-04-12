#define  _CRT_SECURE_NO_WARNINGS 1

#include<Windows.h>
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	//c = a;
	//a = b;
	//b = c;
	//a = a^b;
	//b = a^b;
	//a = a^b;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);

	system("pause");
	return 0;
}