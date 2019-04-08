#define  _CRT_SECURE_NO_WARNINGS 1

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		string output;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] >= 'F' && s[i] <= 'Z')
			{    //A->F
				output += s[i] - 5;
			}
			else if (s[i] >= 'A' && s[i] <= 'F')   //V->A
			{
				output += s[i] + 21;
			}
			else
			{
				output += s[i];
			}
		}
		cout << output << endl;
	}
	return 0;
}