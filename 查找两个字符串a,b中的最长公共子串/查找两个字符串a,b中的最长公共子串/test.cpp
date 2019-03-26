#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input1, input2;
	string output;
	int flag = 0, max = 0;
	while (cin >> input1 >> input2)
	{
		if (input1.size() > input2.size())
			swap(input1, input2);
		string max_str;
		string tmp_str;
		for (int i = 0; i < input1.size(); i++)
		{
			for (int j = i; j<input1.size(); j++)
			{
				tmp_str = input1.substr(i, j - i + 1);
				if (int(input2.find(tmp_str))< 0)
				{
					break;
				}
				else if (max_str.size()<tmp_str.size())
				{
					max_str = tmp_str;
				}
			}
		}
		cout << max_str << endl;
	}
}