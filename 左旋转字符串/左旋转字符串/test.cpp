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
		newstr = str.substr(0, n);//��0-nλ���ַ��洢��newstr��
		str.erase(0, n);//��str��0-nλɾ��
		str += newstr;
		return str;
	}
};

int main()
{
	return 0;
}