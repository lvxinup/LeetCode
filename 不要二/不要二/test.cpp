#define  _CRT_SECURE_NO_WARNINGS 1

//����Ҫ�ҹ��ɣ�ֱ�ӵ���
//����һ������a[1000][1000],��ʼֵ��Ϊ0����a[0][0]��ʼ,��a[0][2]��a[2][0]��Ϊ-1,�������飬����-1�ĵط����Էŵ���
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