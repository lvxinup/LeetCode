#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int i;
	string s;
	vector<string> tmp;
	while (cin >> i)
	{
		while (i+1)
		{
			getline(cin, s);
			tmp.push_back(s);
			i--;
		}
		for (int i = 1; i < tmp.size(); i++)
		{
			if (tmp[i].find(' ') == string::npos && tmp[i].find(',') == string::npos)
				cout << tmp[i] << ','<<" ";
			else
				cout << '\"' << tmp[i] << '\"' << ',' << ' ';
		}
		cout << endl;
	}

	return 0;
}