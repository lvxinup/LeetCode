#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	size_t pos = 0;
	size_t i = 0;
	size_t cur = 0;
	for (i = 0; i < b.size(); i++)
	{
		while (pos < a.size())
		{
			pos = a.find(b[i], cur);
			for (size_t j = pos; j<a.size(); j++)
			{
				a[j] = a[j + 1];
			}

		}
		pos = 0;
	}
	cout << a << endl;

	system("pause");
	return 0;
}