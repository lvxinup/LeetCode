#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<Windows.h>

//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		while (n)
//		{
//			if (n & 1)
//				count++;
//			n = n >> 1;
//		}
//		return count;
//	}
//};

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			++count;
			n = (n - 1)&n;
		}
		return count;
	}
};

int main()
{
	Solution s;
	int n = 7;
	int i = 0;
	i = s.NumberOf1(n);
	std:: cout << i << std::endl;


	system("pause");
	return 0;
}