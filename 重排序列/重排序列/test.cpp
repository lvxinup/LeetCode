#define  _CRT_SECURE_NO_WARNINGS 1
//
//4 2
//1 2 4 3
//1 3
//0 2
//��������
//ʱ�����ƣ�C / C++���� 1000MS���������� 3000MS
//�ڴ����ƣ�C / C++���� 65536KB���������� 589824KB
//��Ŀ������
//����һ������ΪN������A1��AN������Ҫ�����н���M�β�����ÿ�β��������е�ǰ�������������������У�
//�󾭹���M�β�����õ������С�

//��һ�а�����������N��M��1��N��M��105��
//
//�ڶ��а���N���ո����������A1��AN��1��Ai��109��
//
//������M�У�ÿ�а�����������t��x��0��t��1��1��x��N����t = 0�����ʾ��A1��Ax�����������У�
//��t = 1�����ʾ��A1��Ax���н������С�����ִ��˳��������˳��һ�¡�
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
