#define  _CRT_SECURE_NO_WARNINGS 1

// 给出三个整数a，b，c，你需要计算数2a + 2b - 2c在二进制表示下1的个数。
//给出三个整数a，b，c，你需要计算数2a + 2b - 2c在二进制表示下1的个数。
//
//输入
//第一行包含三个整数a, b, c。1≤c＜b＜a≤109
//
//输出
//输出对应的答案。
//
//提示：2 ^ 3 + 2 ^ 2 - 2 ^ 1 = 10 = (1010)2

#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int flag = 0;
		if (a < c && b < c)
		{
			flag += 1;
			int tmp = a>b ? a : b;
			flag += (c - tmp - 1);
			if (a == b || ((a-b==1)&&(c-tmp==1)) || c-tmp==1)
				flag += 1;
			else 
				flag += 2;
		}
		else
		{
			if (a != c && b != c)
			{
				flag = flag + 2;
			}
			else if (a != c && b == c)
			{
				flag += 1;
			}
			else if (a == c && b != c)
			{
				flag += 1;
			}
			else if (a == b && b == c)
			{
				flag += 1;
			}
		}
		cout << flag << endl;
	}
	return 0;
}

