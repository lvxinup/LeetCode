#define  _CRT_SECURE_NO_WARNINGS 1

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b){
		size_t pos = 0;
		int output = 0;
		while ((pos = a.find(b, pos)) != string::npos){    //ур╣╫ак
			pos += b.size();
			output++;
		}
		cout << output << endl;
	}
	return 0;
}