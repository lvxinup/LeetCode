
//��������Ϸ
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void menu()
{
	printf("******************\n");
	printf("***** 1.play *****\n");
	printf("***** 2.exit *****\n");
	printf("******************\n");
}
void game()
{
	int output = 0;
	int answer = 0;
	answer = rand()%100+1;
	while (1)
	{
		printf("��������Ĵ�:\n");
		scanf_s("%d", &output);
		if (output > answer)
		{
			printf("�´���\n");
		}
		if (output < answer)
		{
			printf("��С��\n");
		}
		if (output == answer)
		{
			printf("�¶���\n");
			break;
		}
	}

}
int main()
{
	int input=0;
	menu();
	printf("��ѡ��:\n");
	scanf_s("%d", &input);
	switch (input)
	{
	case 1: game();
	case 0: break;
	default: printf("�����������������\n");
	}
	system("pause");
	return 0;
}
