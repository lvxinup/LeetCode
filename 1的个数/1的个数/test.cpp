#define  _CRT_SECURE_NO_WARNINGS 1

// ������������a��b��c������Ҫ������2a + 2b - 2c�ڶ����Ʊ�ʾ��1�ĸ�����
//������������a��b��c������Ҫ������2a + 2b - 2c�ڶ����Ʊ�ʾ��1�ĸ�����
//
//����
//��һ�а�����������a, b, c��1��c��b��a��109
//
//���
//�����Ӧ�Ĵ𰸡�
//
//��ʾ��2 ^ 3 + 2 ^ 2 - 2 ^ 1 = 10 = (1010)2

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

