#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>

int main()
 {
 	int ch = 0;
 	while((ch=getchar()) != EOF)
 	{
 		if(ch>='a' && ch<='z')
 		{
 			putchar(ch-32);
			printf("\n");
 		}
 		else if(ch >= 'A' && ch <= 'Z')
 		{
 			putchar(ch+32);
			printf("\n");
 		}
 	}
 	return 0;
 }