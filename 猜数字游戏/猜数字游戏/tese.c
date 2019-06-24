
//猜数字游戏
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
		printf("请输入你的答案:\n");
		scanf_s("%d", &output);
		if (output > answer)
		{
			printf("猜大了\n");
		}
		if (output < answer)
		{
			printf("猜小了\n");
		}
		if (output == answer)
		{
			printf("猜对了\n");
			break;
		}
	}

}
int main()
{
	int input=0;
	menu();
	printf("请选择:\n");
	scanf_s("%d", &input);
	switch (input)
	{
	case 1: game();
	case 0: break;
	default: printf("输入错误，请重新输入\n");
	}
	system("pause");
	return 0;
}
