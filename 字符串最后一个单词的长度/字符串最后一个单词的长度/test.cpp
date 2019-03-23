#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))	//	当输入中含有空格时，使用cin输入会在空格处中断，需要使用getline
	{
		//string newstr;
		size_t pos = str.rfind(' ', str.size());//找到最后一个空格的位置
		//newstr=str.substr(pos,str.size()-pos);
		cout << str.size() - pos - 1 << endl;
	}
	return 0;
}