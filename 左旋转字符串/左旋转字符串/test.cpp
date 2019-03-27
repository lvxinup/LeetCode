#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (n<0)
			return NULL;
		if (n == 0)
			return str;
		string newstr = "";
		newstr = str.substr(0, n);//把0-n位的字符存储在newstr中
		str.erase(0, n);//把str的0-n位删除
		str += newstr;
		return str;
	}
};

int main()
{
	return 0;
}