#define  _CRT_SECURE_NO_WARNINGS 1

//形如a^3=b^3+c^3+d^3的数称为完美立方等式。例如12^3=6^3+8^3+10^3.
//编写一个程序，对任给的正整数N，寻找所有的4元组(a,b,c,d)，使得a^3=b^3+c^3+d^3。
//其中a,b,c,d大于1，小于等于N，且b<=c<=d
//输入：一个正整数N(N<=100)
//输出：Cube=a,Triple=(b,c,d)

//思路
//四重循环枚举a,b,c,d,a在最外层，d在最里层，每一层都从小到大枚举
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
