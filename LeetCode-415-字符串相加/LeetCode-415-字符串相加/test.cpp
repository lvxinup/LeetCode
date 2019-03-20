#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	string addStrings(string num1, string num2) {
		int size1 = num1.size() - 1;
		int size2 = num2.size() - 1;
		int ret = 0;
		string newstr = "";
		while (size1 >= 0 || size2 >= 0)
		{
			int a = 0;
			int b = 0;
			if (size1 >= 0)
			{
				a = num1[size1] - '0';
				size1--;
			}
			else
			{
				a = 0;
			}
			if (size2 >= 0)
			{
				b = num2[size2] - '0';
				size2--;
			}
			else
			{
				b = 0;
			}
			int sum = a + b + ret;
			newstr.insert(newstr.begin(), sum % 10 + '0');
			ret = sum / 10;
		}
		if (ret == 1)
			newstr = "1" + newstr;
		return newstr;
	}
};