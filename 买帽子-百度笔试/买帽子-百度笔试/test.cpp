#define  _CRT_SECURE_NO_WARNINGS 1

#include<set>
#include<iostream>
using namespace std;
int main()
{
	set<int> tmp;
	int input;
	cin >> input;
	for (int i = 0; i<input; i++)
	{
		int cur;
		cin >> cur;
		tmp.insert(cur);
	}
	if (tmp.size()<3)
	{
		cout << -1;
		return 0;
	}
	auto x = tmp.begin();
	x++; x++;
	cout << *x;

	return 0;
}
