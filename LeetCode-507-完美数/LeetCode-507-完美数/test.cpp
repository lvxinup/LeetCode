#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>8
using namespace std;

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1)
			return false;
		int flag = num - 1;
		int Sqrt = sqrt(num);
		for (int i = 2; i <= Sqrt; i++)
		if (num%i == 0)
			flag = flag - i - num / i;
		if (0 == flag)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	bool tmp = s.checkPerfectNumber(28);
	if (tmp)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}