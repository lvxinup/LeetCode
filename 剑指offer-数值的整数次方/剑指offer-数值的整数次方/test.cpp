#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	double Power(double base, int exponent) {
		int flag = 0;
		if (exponent == 0)
			return 1;
		if (exponent<0)
		{
			flag = 1;
			exponent = -exponent;
		}
		double result = 1.0;
		for (int i = 1; i <= exponent; i++)
			result *= base;
		if (flag == 1)
			return 1.0 / result;
		else
			return result;
	}
};