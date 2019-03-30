#include<iostream>
#include<stdio.h>
using namespace std;

int Count(int rows, int cols, int add)
{
	int tmp = 0;
	for (int i = 0; i < rows; ++i)
	for (int j = 0; j < cols; ++j)
	{
		int cur1 = i;
		int cur2 = j;
		int sum = 0;
		while (cur1) {
			sum += cur1 % 10;
			cur1 /= 10;
		}
		while (cur2) {
			sum += cur2 % 10;
			cur2 /= 10;
		}
		if (sum < add)
			++tmp;
		else if (rows == 1 || cols == 1)
			return tmp;
	}

	return tmp;
}
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	cout << Count(m, n, k) << endl;

	return 0;
}