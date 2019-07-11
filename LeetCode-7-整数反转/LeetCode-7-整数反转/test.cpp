#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>
using namespace std;

//-2147483648¡ª¡ª2147483647
class Solution {
public:
	int reverse(int x) {
		long  output = 0;
		while (x != 0){
			output = output * 10 + (x % 10);
			x = x / 10;
		}
		if (output > INT_MAX || output < INT_MIN)
			return 0;
		return output;

	}
};

int main()
{
	Solution s;
	cout << s.reverse(-123) << endl;
	system("pause");
	return 0;
}