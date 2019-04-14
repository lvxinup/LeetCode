#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
using namespace std;
int main()
{
	int all,a;
	set<int> tmp;
	cin >> all;
	while (all-- && cin >> a)
		tmp.insert(a);

}