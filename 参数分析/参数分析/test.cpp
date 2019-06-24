#define  _CRT_SECURE_NO_WARNINGS 1

//在命令行输入如下命令：
//xcopy / s c : \ d : \，
//各个参数如下：
//参数1：命令字xcopy
//参数2：字符串 / s
//参数3：字符串c : \
//参数4 : 字符串d : \
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//解析规则：
//1.参数分隔符为空格
//2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//3.参数不定长
//4.输入由用例保证，不会出现不符合要求的输入

#include<string>
#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

int main()
{
	string s;
	vector<string> v;
	int i = 0, flag = 0;    //标志是否有引号出现
	int pos1 = 0, pos2 = 0; 
	int pos;//pos1表示空格位置，POS2表示引号位置
	int tmp;
	getline(cin, s);
	while(i<s.size())
	{
		string cur;
		pos = s.find(' ', i);//从pos1位置找空格
		tmp = s.find('"', i);//从pos2开始找引号
		if (tmp !=string::npos && flag == 0)//找到引号，并且flag为0，说明之前没有引号
		{
			pos2 = tmp;
			flag = 1;
			i = tmp+1;
		}
		else if (tmp != string::npos && flag == 1)//找到引号，并且flag为1，说明找到引号内的字符串
		{
			cur = s.substr(i, tmp - i);
			v.push_back(cur);
			i = tmp+1;
		}
		if (pos != string::npos && flag == 1 && pos<tmp)    //找到空格,并且有引号存在
		{
			cur = s.substr(i, pos - i);
			v.push_back(cur);
			i = pos + 1;
		}
		else if (pos != string::npos && flag == 0)    //找到空格，并且没有引号存在
		{
			cur = s.substr(i, pos - i);
			v.push_back(cur);
			i = pos + 1;
		}
		if (pos == string::npos&&tmp == string::npos)//没有空格，没有引号，说明剩最后一个字符串
		{
			cur = s.substr(i, s.size() - i);
			v.push_back(cur);
			break;
		}
	}
	cout << v.size() << endl;
	for (auto& e : v)
		cout << e << endl;

	system("pause");
	return 0;
}