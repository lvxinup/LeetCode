#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			flag += NumberOf1(i);
		}
		return flag;
	}
	int NumberOf1(int tmp)
	{
		// 10   11   101   1311
		int cur = 0;
		while (tmp)
		{
			if (tmp % 10 == 1)
				cur++;
			tmp /= 10;
		}
		return cur;
	}
};

int main()
{
	Solution s;
	int n;
	while (cin >> n)
	std::cout << s.NumberOf1Between1AndN_Solution(n) << std::endl;

	return 0;
}