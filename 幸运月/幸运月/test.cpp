#define  _CRT_SECURE_NO_WARNINGS 1

//在游戏里，会存在一些特殊的日子，使玩家获得一些额外的奖励。比如说，在生日这一天，玩家可以领取一份生日礼物。
//这次，希望存在一些幸运月，玩家的好运翻倍。根据星座占卜，如果一个月的天数大于一定天数D时，该月就是幸运月。
//现在给定一个年份Y，你需要输出该年有多少个幸运月。

//1
//2017 30


#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

int main()
{
	long long int year,n;
	int day;
	int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	while (cin >> n)
	{	
		vector<vector<int>> input;
		for (int i = 0; i < n; i++)
		{
			vector<int> tmp;
			cin >> year >> day;
			tmp.push_back(year);
			tmp.push_back(day);
			input.push_back(tmp);
		}
		for (int i = 0; i < n;i++)
		{
			int flag = 0;
			if (input[i][0] % 400 == 0 || (input[i][0] % 4 == 0 && input[i][0] % 100 != 0))
			{
				month[1] = 29;
			}
			else
				month[1] = 28;
			for (int j = 0; j < 12; j++)
			{
				if (month[j]>input[i][1])
					flag++;
			}
			cout << flag << endl;
		}
	}
	

	system("pause");
	return 0;
}