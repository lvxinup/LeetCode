#define  _CRT_SECURE_NO_WARNINGS 1

//最近一款吃鸡类型的游戏火爆全球。在组队模式下，你可以邀请自己的好友组建自己的小队，并选择是否填充（是否同意和非好友游玩），
//然后加入游戏。现在有A个单人队伍，B个双人队伍，C个三人队伍，D个四人队伍，
//并且全都同意填充，请问最多能组成多少个四人队伍。

//4
//1 2 3 4
//4 3 2 1
//2 2 2 1
//0 2 0 1

//#include<iostream>
//#include<vector>
//#include<Windows.h>
//
//using namespace std;
// 
//int main()
//{
//	int tmp;
//	cin >> tmp;
//	int a, b, c, d;
//	int i = 0;
//	while (tmp)
//	{
//		int flag = 0,cur1,cur2,cur3;//cur用来记录剩下的各个位的数量
//		cin >> a >> b >> c >> d;
//		flag += d;	//4人队都加给flag
//		//cur2 = flag;
//
//		//b = b - (flag - cur2) * 2;
//		if (c > a)
//		{
//			flag += a;
//			a = 0;
//		}
//		else if (c == a)
//		{
//			flag += c;
//			a = 0;
//		}
//		else //c<a
//		{
//			cur1 = flag;
//			flag += c;
//			a = a - (flag - cur1);
//
//		}
//		flag += (b / 2);
//		b = b % 2;
//		if (b == 1 && a >= 2)
//		{
//			b--;
//			a -= 2;
//			flag++;
//		}
//		flag += (a / 4);
//		cout << flag << endl;
//		tmp--;
//	}
//
//		system("pause");
//	return 0;
//}


#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;

int main()
{
	int tmp;
	cin >> tmp;
	int a, b, c, d;
	//int cur[100][5] = { 0 };
	vector<vector<int>> v(tmp, vector<int>(4, 0));
	int index = 0;
	for (int i = 0; i < tmp; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &index);
			//cur[i][j] = index;
			v[i][j] = index;
		}
	}
	for (int k = 0; k < tmp; k++)
	{
		int flag = 0, cur1=0, cur2=0, cur3=0;//cur用来记录剩下的各个位的数量
		a = v[k][0]; b = v[k][1]; c = v[k][2]; d = v[k][3];
		flag += d;	//4人队都加给flag
		//cur2 = flag;
		
		//b = b - (flag - cur2) * 2;
		if (c > a)
		{
			flag += a;
			a = 0;
		}
		else if (c == a)
		{
			flag += c;
			a = 0;
		}
		else //c<a
		{
			cur1 = flag;
			flag += c;
			a = a - (flag - cur1);	
		}
		flag += (b / 2);
		b = b % 2;
		if (b == 1 && a >= 2)
		{
			b--;
			a -= 2;
			flag++;
		}
		flag += (a / 4);
		cout << flag << endl;
	}
	system("pause");
	return 0;
}