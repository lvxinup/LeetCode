#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		//���룺1.+��-���֣���֤���ź���������
		//     2.e,E��ǰ��Ҫ�����֣���ѧ������
		//     3.С����ֻ����һ��
		//     4.�����������ĸ,�Ƿ�����    E 69    e 101
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
			if ((*string - '0') >= 0 && (*string - '0') <= 9)//�����������ĸ,�Ƿ�����    E 69    e 101
			{
				string++;
				num = 1;
			}
			else if (*string == '.')//���������,С����ֻ����һ��
			{
				if (pointnum>0 || nume>0)//һ��С������e֮������С��
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