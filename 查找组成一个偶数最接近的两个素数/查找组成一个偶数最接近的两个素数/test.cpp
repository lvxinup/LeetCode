#define  _CRT_SECURE_NO_WARNINGS 1

	#include<iostream>
	#include<vector>
	#include<math.h>

	using namespace std;
	bool issushu(int i)    //ÕÒËØÊı
	{
		vector<int> cur;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				return false;
		}
		return true;
	}
	int main()
	{
		int a;
		while (cin >> a)
		{
			for (int i = a / 2; i >= 0; i--)
			{
				if (issushu(i) && issushu(a - i))
				{
					cout << i << endl;
					cout << a - i << endl;
					break;
				}
			}
		}
		return 0;
	}