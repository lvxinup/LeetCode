#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

//��ʯ����M  �Ǳ�������A1  �Ǳ�Ѫ��H1  ������A2  ������B2  Ѫ��H2  ��������C1  ��������C2   Ͷʯ��C
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
				long int cur = 0;	//��ʾ�������˺�
				int b2 = input[j][4] + i;	//������
				int a2 = input[j][3] + (b2 * 20) / 10;	//������
				int h1 = input[j][2], h2 = input[j][5];	//��ʾѪ��
				while (h1>0 && h2>0)	//���������ʱ����ս��
				{
					int index1 = a2;	//���˵Ĺ�����
					int index2 = input[j][1] - b2;	//�Ǳ��Ĺ�����
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