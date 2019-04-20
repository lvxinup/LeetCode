#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		//问题在于把一个字符替换成3个字符
		if (str == NULL)
		{
			return;
		}
		int i = 0;
		int strlength = 0;
		int blacknum = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			strlength++;
			if (str[i] == ' ')
				++blacknum;
		}
		int len = strlength + 2 * blacknum;
		if (len + 1 > length)
			return;

		char* str1 = str + strlength;
		char* str2 = str + len;
		while (str1 < str2)
		{
			if (*str1 == ' ')
			{
				*str2-- = '0';
				*str2-- = '2';
				*str2-- = '%';
			}
			else
			{
				*str2-- = *str1;
			}
			--str1;
		}

	}
	void print(char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			cout << str[i];
			i++;
		}
	}
};

int main()
{
	Solution a;
	char* str = "we are happy";
	int length = sizeof(str);
	a.replaceSpace(str, 16);
	a.print(str);
	system("pause");
	return 0;
}