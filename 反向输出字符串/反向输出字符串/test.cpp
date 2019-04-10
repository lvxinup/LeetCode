#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include<Windows.h>
#include<stack>

using namespace std;
int main() {
	string s;
	getline(cin, s);
	size_t pos = 0;
	int cur = 1;
	int size = s.size();
	stack<string> v;
	while (cur>0)
	{
		cur = s.find(' ', pos);
		string tmp = s.substr(pos, cur-pos);
		v.push(tmp);
		pos = cur+1;
	}
	while (v.size()) {
			cout << v.top() << " ";
			v.pop();
	}

	system("pause");
	return 0;
}