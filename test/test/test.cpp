#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

class Soulution
{
public:
	Soulution(vector<int> tmp)
	{
		for (int i = 0; i < tmp.size(); i++)
		{
			A.push_back(tmp[i]);
		}
	}
	void operator��(vector<int>& tmp)	//����
	{
		for (int i = 0; i < A.size(); i++)
		{
			cout << A[i] << " ";
		}
		int flag = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			flag = 0;
			for (int j = 0; j < A.size(); j++)
			{
				if (A[j] == tmp[i])
				{
					flag++;
				}
			}
			if (flag == 0)
				cout << tmp[i] << " ";
		}
		cout << endl;
	}
	void operator��(vector<int>& tmp)	//����
	{
		int flag = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				if (A[j] == tmp[i])
				{
					flag = 1;
					break;
				}
				else
					flag = 0;

			}
			if (flag == 1)
				cout << tmp[i] << " ";
			flag = 0;
		}
		cout << endl;
	}
	void operator-(vector<int>& tmp)
	{
		int flag = 0;
		for (int i = 0; i < A.size(); i++)
		{
			flag = 0;
			for (int j = 0; j < tmp.size(); j++)
			{
				if (A[i] == tmp[j])
				{
					flag = 1;
				}
			}
			if (flag ==0)
				cout << A[i] << " ";
		}
		cout << endl;
	}
private:
	vector<int> A; 
};

int main()
{
	vector<int> A,B;
	int a,tmp;
	cout << "����������A�Ĵ�С��" << endl;
	cin >> a;
	cout << "����������A��ֵ��"<<endl;
	while (a)
	{
		cin >> tmp;
		A.push_back(tmp);
		a--;
	}
	cout << "����������A�Ĵ�С��" << endl;
	cin >> a;
	cout << "����������B��ֵ��" << endl;
	while (a)
	{
		cin >> tmp;
		B.push_back(tmp);
		a--;
	}
	Soulution s(A);
	
	cout << "A-BΪ: ";
	s.operator-(B);
	cout << "A��BΪ��";
	s.operator��(B);
	cout << "A��BΪ��";
	s.operator��(B);
	system("pause");
	return 0;
}