#define  _CRT_SECURE_NO_WARNINGS 1

//���ڸ���һ�ź���n����������޻�ͼ�����ǳ�����ͼ�ǡ�����ͼ�����ҽ������ͼ��������������
//1.   ����һ��1 - n���ֵ�ȫ����p������i�Ž���ȨֵΪp[i]��
//2.   ���ͼ�д���u�Ž�㵽v�Ž���һ���ߣ���u�Ž���ȨֵҪС��v�Ž���Ȩֵ��
//��Ȼ�����ж���������������������ҳ��ֵ�����С��ȫ����p��ʹ�����ͼ��Ϊ����ͼ��

//��һ�а�������������n��m, �ֱ��ʾͼ�Ͻ��������������ߵ���������1��n, m��100000��
//������m��ÿ��������������u��v����ʾ����һ����u��㵽v��������ߡ�
//
//���һ���ֵ�����С�ģ�1 - n��ȫ���У�ʹ������ͼ������ͼ��Ԫ���м�ʹ�ÿո������

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