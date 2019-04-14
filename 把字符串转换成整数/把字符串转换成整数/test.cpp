#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

int strtoint(const char* str)	//字符串转换成整数
{
	//1.空指针 str==NULL
	//2.指针为空	str="";
	//3.非法输入	符号、字母、两个符号+-
	//4.直接为数字，没有符号

	if (str == NULL && *str == '\0')	//空指针&&指针为空
	{
		return -1;
	}
	
	//运行到这一步，就排除了空指针str==NULL及指针为空str=='\0'两种情况
	int flag = false;
	//判断第一个字符的类型
	if (*str == '+')	//第一位为+
	{
		str++;
	}
	else if (*str == '-')	//第一位为-
	{
		flag = true;
		str++;
	}
	long long num = 0;
	while(*str != '\0')	//如果没有到字符串结尾
	{
		if (*str >= '0' && *str < '9')
		{
			int tmp = flag ? -1 : 1;
			num = num * 10 + tmp*(*str - '0');

			//整数超出范围
			if ((!flag && num > 0x7FFFFFFF) || (flag && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	return num;
}
int main()
{
	char str = '123';
	cout << strtoint(&str) << endl;
	system("pause");
	return 0;

}