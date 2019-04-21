#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<unordered_set>
using namespace std;

int main()
{
	int n;
	
	unordered_set<string> connect;
	vector<int> tmp;
	int max = 0;	
	while (cin >> n)
	{
		string left, right;
		cin >> left >> right;
		if (connect.find(left) != connect.end())
		{
			if (right == "disconnect")
				connect.erase(left);
		}
		else
		{
			if (right == "connect")
			{
				if (max == connect.size()) ++max;
				connect.emplace(left);
			}
		}
		n--;
	}
	cout << max << endl;

	system("pause");
	return 0;
}