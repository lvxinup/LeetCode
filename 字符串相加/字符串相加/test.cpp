#define  _CRT_SECURE_NO_WARNINGS 1

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//注意：
//
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0 - 9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

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