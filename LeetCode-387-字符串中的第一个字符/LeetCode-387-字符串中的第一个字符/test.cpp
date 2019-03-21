#define  _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
#include<unordered_map>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> map;
		for (auto& e : s)
			++map[e];
		for (int i = 0; i<s.size(); i++)
		{
			if (map[s[i]] == 1)
				return i;
		}
		return -1;
	}
};

int main()
{
	string s("LeetCode");
	Solution S;
	cout<<S.firstUniqChar(s);

	system("pause");
	return 0;
}