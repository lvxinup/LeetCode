#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

//extern char arr[];
//extern char *p;

//struct Test
//{
//	int Num;
//	char *pcName;
//	//shortsDate;
//	char cha[2];
//	//shortsBa[4];
//}*p;

int main()
{

	//int arr[10] = { 0 };

	//printf("������Ԫ�صĵ�ַarr��%p\n", arr);
	//printf("����ĵ�ַ&arr��%p\n", &arr);
	//printf("�����ַ����һ����ַ��%p\n", &arr + 1);

	//printf("%s\n", arr);
	//printf("%s\n", p);
		
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));

	
	//p = 0x100000;
	//printf("%s\n", 0x100000 + 0x1);


	system("pause");
	return 0;
}