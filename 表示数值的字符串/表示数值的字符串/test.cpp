#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		//输入：1.+、-数字，保证符号后面有数字
		//     2.e,E的前后都要有数字，科学计数法
		//     3.小数点只能有一个
		//     4.输入包含有字母,非法输入    E 69    e 101
		if (string == NULL)
			return false;
		if (*string == '+' || *string == '-')
		{
			string++;
		}
		if (*string == '\0')
			return false;
		int i = 0;
		int pointnum = 0, nume = 0, num = 0;
		while (*string != '\0')
		{
			if ((*string - '0') >= 0 && (*string - '0') <= 9)//输入包含有字母,非法输入    E 69    e 101
			{
				string++;
				num = 1;
			}
			else if (*string == '.')//第三种情况,小数点只能有一个
			{
				if (pointnum>0 || nume>0)//一个小数点且e之后不能有小数
					return false;
				string++;
				pointnum++;
			}
			else if (*string == 'e' || *string == 'E')
			{
				if (nume>0 || num == 0)
					return false;
				string++;
				nume++;
				if (*string == '+' || *string == '-')
				{
					string++;
				}
				if (*string == '\0')
					return false;
			}
			else
				return false;
		}
		return true;
	}

};
int main()
{
	char* test = "123.45e+6";
	Solution a;
	a.isNumeric(test);

	return 0;
}