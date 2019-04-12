#define  _CRT_SECURE_NO_WARNINGS 1

//不需要找规律，直接递推
//定义一个数组a[1000][1000],初始值都为0，从a[0][0]开始,将a[0][2]和a[2][0]置为-1,遍历数组，不是-1的地方可以放蛋糕
#include<iostream>
using namespace std;
int a[1000][1000] = { 0 };
int main()
{
	int w, h, res = 0;
	cin >> w >> h;

	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2)<w) a[i + 2][j] = -1;
				if ((j + 2)<h) a[i][j + 2] = -1;
			}
		}
	}
	cout << res;
	return 0;
}