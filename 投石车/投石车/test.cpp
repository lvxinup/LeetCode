#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

//钻石数量M  城堡攻击力A1  城堡血量H1  攻击力A2  防御力B2  血量H2  升级攻击C1  升级防御C2   投石车C
//  1100       10              100       1           1       10        10           20        1000

int main()
{
	long long int n,M,A1,H1,A2,B2,H2,C1,C2,C;
	while (cin >> n)
	{
		vector<vector<int>> input;
		for (int i = 0; i < n; i++)
		{
			vector<int> tmp;
			cin >> M>>A1>> H1>> A2>> B2>> H2>> C1>> C2>> C;
			tmp.push_back(M);
			tmp.push_back(A1);
			tmp.push_back(H1);
			tmp.push_back(A2);
			tmp.push_back(B2);
			tmp.push_back(H2);
			tmp.push_back(C1);
			tmp.push_back(C2);
			tmp.push_back(C);
			input.push_back(tmp);
		}

		for (int j = 0; j < n; j++)
		{
			long int max = 0;
			int tmp = input[j][0] - input[j][8];
			for (int i = 0; i < tmp / 20; i++)
			{
				long int cur = 0;	//表示产生的伤害
				int b2 = input[j][4] + i;	//防御力
				int a2 = input[j][3] + (b2 * 20) / 10;	//攻击力
				int h1 = input[j][2], h2 = input[j][5];	//表示血量
				while (h1>0 && h2>0)	//两个都存活时进行战斗
				{
					int index1 = a2;	//商人的攻击力
					int index2 = input[j][1] - b2;	//城堡的攻击力
					h1 -= index1;
					h2 -= index2;
				}
				cur = input[j][2] - h1;
				if (cur >= max)
					max = cur;
			}
			if (max > 100)
				max = 100;
			cout << max << endl;
		}
	}
		
	return 0;
}