#define  _CRT_SECURE_NO_WARNINGS 1

//����a^3=b^3+c^3+d^3������Ϊ����������ʽ������12^3=6^3+8^3+10^3.
//��дһ�����򣬶��θ���������N��Ѱ�����е�4Ԫ��(a,b,c,d)��ʹ��a^3=b^3+c^3+d^3��
//����a,b,c,d����1��С�ڵ���N����b<=c<=d
//���룺һ��������N(N<=100)
//�����Cube=a,Triple=(b,c,d)

//˼·
//����ѭ��ö��a,b,c,d,a������㣬d������㣬ÿһ�㶼��С����ö��
//a->[2, N]	b->[2, a - 1]	c->[b, a - 1]	d->[c,a-1]

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <i; j++)
				for (int k = j; k <i; k++)
					for (int l = k; l <i; l++)
						if (i*i*i == j*j*j + k*k*k + l*l*l)
							printf("Cube=%d,Triple=(%d,%d,%d)\n", i, j, k, l);
	}

	return 0;
}
