#define  _CRT_SECURE_NO_WARNINGS 1

//����Ϸ������һЩ��������ӣ�ʹ��һ��һЩ����Ľ���������˵����������һ�죬��ҿ�����ȡһ���������
//��Σ�ϣ������һЩ�����£���ҵĺ��˷�������������ռ�������һ���µ���������һ������Dʱ�����¾��������¡�
//���ڸ���һ�����Y������Ҫ��������ж��ٸ������¡�

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