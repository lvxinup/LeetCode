#define  _CRT_SECURE_NO_WARNINGS 1

//���һ��Լ����͵���Ϸ��ȫ�������ģʽ�£�����������Լ��ĺ����齨�Լ���С�ӣ���ѡ���Ƿ���䣨�Ƿ�ͬ��ͷǺ������棩��
//Ȼ�������Ϸ��������A�����˶��飬B��˫�˶��飬C�����˶��飬D�����˶��飬
//����ȫ��ͬ����䣬�����������ɶ��ٸ����˶��顣

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
//		int flag = 0,cur1,cur2,cur3;//cur������¼ʣ�µĸ���λ������
//		cin >> a >> b >> c >> d;
//		flag += d;	//4�˶Ӷ��Ӹ�flag
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
		int flag = 0, cur1=0, cur2=0, cur3=0;//cur������¼ʣ�µĸ���λ������
		a = v[k][0]; b = v[k][1]; c = v[k][2]; d = v[k][3];
		flag += d;	//4�˶Ӷ��Ӹ�flag
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