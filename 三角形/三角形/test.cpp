#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ismax(string& a,string& b,string& c)
{
	int i,j;
	string tmp;
	int flag = 0;//表示进位
	int index, cur;
	for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
		index = (a[i] - '0') + (b[j] - '0') + flag;
		tmp = (char)(index % 10 + '0') + tmp;
		flag = index / 10;
	}
	while (i >= 0)
	{
		index = (a[i] - '0')  + flag;
		tmp = (char)(index % 10 + '0') + tmp;
		flag = index / 10;
		i--;
	}
	while (j >= 0)
	{
		index = (b[j] - '0') + flag;
		tmp = (char)(index % 10 + '0') + tmp;
		flag = index / 10;
		j--;
	}
	if (flag > 0)
		tmp = tmp + (char)(flag + '0');

	if (tmp.size() > c.size())
		return true;
	else if (tmp.size() < c.size())
		return false;
	else
		return tmp>c;
}
int main()
{
	string a, b, c;//表示三角形的三边
	while (cin>>a>>b>>c)
	{
		if (ismax(a, b, c) && ismax(a, c, b) && ismax(b, c, a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}