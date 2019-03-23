#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	int flag = 0, a, cur;
	while (cin >> a)
	{
		flag = 0;
	while (a)
	{
		
		cur = 0;
		for (int i = 1; i <= a / 2; i++)
		{
			if (a%i == 0)
				cur += i;
		}
		if (cur == a)
			flag++;
		a--;
	}
	if (flag >= 0)
		cout << flag<<endl;
	else
		cout << -1<<endl;
	}
	

	system("pause");
	return 0;
}