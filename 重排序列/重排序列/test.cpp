#define  _CRT_SECURE_NO_WARNINGS 1
//
//4 2
//1 2 4 3
//1 3
//0 2
//重排序列
//时间限制：C / C++语言 1000MS；其他语言 3000MS
//内存限制：C / C++语言 65536KB；其他语言 589824KB
//题目描述：
//给定一个长度为N的序列A1到AN，现在要对序列进行M次操作，每次操作对序列的前若干项进行升序或降序排列，
//求经过这M次操作后得到的序列。

//第一行包含两个整数N和M，1≤N，M≤105。
//
//第二行包含N个空格隔开的整数A1到AN，1≤Ai≤109。
//
//接下来M行，每行包含两个整数t和x，0≤t≤1，1≤x≤N。若t = 0，则表示对A1到Ax进行升序排列；
//若t = 1，则表示对A1到Ax进行降序排列。操作执行顺序与输入顺序一致。
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int M, N, i = 0;
	cin >> N >> M;
	string s;
	vector<int> cur;
	while (N)
	{
		int index = 0;
		cin >> index;
		cur.push_back(index);
		N--;
	}
	while (M)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0)
		{
			sort(cur.begin(), cur.begin() + b);
		}
		else if (a == 1)
		{
			reverse(cur.begin(), cur.begin() + b);
		}
		M--;
	}
	for (int i = 0; i < cur.size(); i++)
	{
		cout << cur[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
