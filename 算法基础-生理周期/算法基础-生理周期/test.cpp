#define  _CRT_SECURE_NO_WARNINGS 1

//人有体力、情商、智商的高峰日子，它们分别每隔23天、28天 和33天出现一次。
//对于每个人，我们想知道何时三个高峰落在同一天。
//给定三个高峰出现的日子p, e和i(不一定是第一次高峰出现的日子)，再给定另一个指定的日子d，
//你的任务是输出日子d之后，下一次三个高峰落在同一天的日子(用距离d的天数表示)。
//例如:给定日子为10，下次出现三个高峰同一天的日子是12，则输出2。
//
//输入
//输入四个整数 : p，e，i和d。p， e，i分别表示体力、情感和智力高峰出现的日子。d是给定的日子，可能小于p，e或i。
//所有给定日子是非负的并且小于或等于365，所求的日子小于或等于21252。
//
//输出
//从给定日子起，下一次三个高峰同一天的日子的天数)

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int p, e, i, d;
	while (cin >> p >> e >> i >> d && p!=-1)
	{
		int k = 0;
		for ( k = d + 1; (k - p) % 23; ++k);
		for (; (k - e) % 28; k += 23);
		for (; (k - i) % 33; k += 23 * 28);
		if (k < 21252)
			cout << "the next triple peak occurs in " << k - d << endl;
		else
			cout << "the next triple peak occurs in 21252" << endl;
	}
	return 0;
}