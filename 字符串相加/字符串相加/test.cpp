#define  _CRT_SECURE_NO_WARNINGS 1

//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
//
//ע�⣺
//
//num1 ��num2 �ĳ��ȶ�С�� 5100.
//num1 ��num2 ��ֻ�������� 0 - 9.
//num1 ��num2 ���������κ�ǰ���㡣
//�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

#include<iostream>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int size1 = num1.size() - 1;
		int size2 = num2.size() - 1;
		int ret = 0;
		string newstr = "";
		while (size1 >= 0 || size2 >= 0)
		{
			int a = 0;
			int b = 0;
			if (size1 >= 0)
			{
				a = num1[size1] - '0';
				size1--;
			}
			else
			{
				a = 0;
			}
			if (size2 >= 0)
			{
				b = num2[size2] - '0';
				size2--;
			}
			else
			{
				b = 0;
			}
			int sum = a + b + ret;
			newstr.insert(newstr.begin(), sum % 10 + '0');
			ret = sum / 10;
		}
		if (ret == 1)
			newstr = "1" + newstr;
		return newstr;
	}
	void stringprint(const string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << str[i];
		}
	}
};

int main()
{
	Solution A;
	string newstr = A.addStrings("99", "199");

	A.stringprint(newstr);
	system("pause");
	return 0;
}