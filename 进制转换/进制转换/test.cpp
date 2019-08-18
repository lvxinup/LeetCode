#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<string>

using namespace std;

int main()
{
	int i = 36;
	//printf("%o\n", i);//八进制
	//printf("%x\n", i);//十六进制
	char cur1[20];
	char cur2[20];
	char cur3[20];
	_itoa(i, cur1, 2);
	_itoa(i, cur2, 8);
	_itoa(i, cur3, 16);
	printf("2进制: %s\n", cur1);
	printf("8进制: %s\n", cur2);
	printf("16进制: %s\n", cur3);

	system("pause");
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i;
//	char buffer[33];
//	printf("Enter a number: ");
//	scanf("%d", &i);
//	_itoa(i, buffer, 10);
//	printf("decimal: %s\n", buffer);
//	_itoa(i, buffer, 16);
//	printf("hexadecimal: %s\n", buffer);
//	_itoa(i, buffer, 2);
//	printf("binary: %s\n", buffer);
//	return 0;
//}