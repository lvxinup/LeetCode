#define  _CRT_SECURE_NO_WARNINGS 1

//现在给出一张含有n个点的有向无环图，我们称这张图是“有序图”当且仅当这个图满足以下条件：
//1.   存在一个1 - n数字的全排列p，并令i号结点的权值为p[i]。
//2.   如果图中存在u号结点到v号结点的一条边，则u号结点的权值要小于v号结点的权值。
//显然可能有多个序列满足条件，请你找出字典序最小的全排列p，使得这个图成为有序图。

//第一行包含两个正整数n，m, 分别表示图上结点是数量和有向边的数量。（1≤n, m≤100000）
//接下来m行每行有两个正整数u，v，表示存在一条从u结点到v结点的有向边。
//
//输出一个字典序最小的，1 - n的全排列，使得这张图是有序图，元素中间使用空格隔开。

//3 3
//1 2
//1 3
//3 2
//
//1 3 2

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	vector<int> tmp;
	while (b)
	{
		int left, right;
		cin >> left >> right;
		tmp.push_back(left);
		tmp.push_back(right);
		b--;
	}
	vector<int> output;
	for (int i = 0; i < tmp.size(); i += 2)
	{
		output.erase(output.begin(),output.end());
		output.push_back(tmp[i]);
		output.push_back(tmp[i + 1]);
		for (int j = 0; j < tmp.size(); j += 2)
		{
			if (output[output.size()-1] == tmp[j] && j!=i)
			{
				output.push_back(tmp[j + 1]);
			}
		}
		if (output.size() == a)
			break;
	}
	for (auto x : output)
		cout << x << " ";

	system("pause");
}