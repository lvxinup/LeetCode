#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string t;
	//getline(cin, s);
	//getline(cin, t);
	while (cin >> s >> t)
	{
		for (int i = 1; i < s.size(); i++)
		{
			if (t.find(s[i]) >= 0)
				continue;
			else
				cout << "No" << endl;
		}
		cout << "Yes" << endl;
	}
}