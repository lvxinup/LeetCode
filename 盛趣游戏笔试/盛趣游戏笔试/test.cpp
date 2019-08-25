#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<char> index = { 'S', 'B', 'Q', 'W','Y'};
//4294967291
int main()
{
	long long int tmp;
	while (cin>>tmp){
		string input;
		//首先将 int 转为 string
		while (tmp){
			input += (tmp % 10 + '0');
			tmp = tmp / 10;
		}
		reverse(input.begin(), input.end());
		//先将数字尾插进去，然后再将数额插入
		string output;
		//当大于亿时
		if (input.size() >= 9){
			string cur = input.substr(0, input.size() - 8);
			for (int i = 0; i < cur.size(); i++){
				if (!((i == cur.size() - 1) && (cur[i] == '0')))
					output.push_back(cur[i]);
				if (i < cur.size() - 1 && cur[i] != '0')
					output.push_back(index[cur.size() - i - 2]);
			}
			output.push_back('Y');
			cur = input.substr(input.size()-8,4);
			for (int i = 0; i < cur.size(); i++){
				if (!((i == cur.size() - 1) && (cur[i] == '0')))
					output.push_back(cur[i]);
				if (i < cur.size() - 1 && cur[i] != '0')
					output.push_back(index[cur.size() - i - 2]);
			}
			output.push_back('W');
			cur = input.substr(input.size() - 4, 4);
			for (int i = 0; i < cur.size(); i++){
				if (!((i == cur.size() - 1) && (cur[i] == '0')))
					output.push_back(cur[i]);
				if (i < cur.size() - 1 && cur[i] != '0')
					output.push_back(index[cur.size() - i - 2]);
			}
		}
		//当大于十万时
		else if (input.size() >= 6){
			string cur = input.substr(0, input.size() - 4);
			for (int i = 0; i < cur.size(); i++){
				if (!((i == cur.size() - 1) && (cur[i] == '0')))
					output.push_back(cur[i]);
				if (i < cur.size() - 1 && cur[i] != '0')
					output.push_back(index[cur.size() - i - 2]);
			}
			output.push_back('W');
			cur = input.substr(input.size() - 4, 4);
			for (int i = 0; i < cur.size(); i++){
				if (!((i == cur.size() - 1) && (cur[i] == '0')))
					output.push_back(cur[i]);
				if (i < cur.size() - 1 && cur[i] != '0')
					output.push_back(index[cur.size() - i - 2]);
			}
		}
		else if (input.size() <= 5){
			for (int i = 0; i < input.size(); i++){
				if (!((i == input.size() - 1) && (input[i] == '0')))
					output.push_back(input[i]);
				if (i < input.size() - 1 && input[i] != '0')
					output.push_back(index[input.size() - i - 2]);
			}
		}
		cout << output << endl;
	}
			

	return 0;
}

/*
long long int tmp;
while (cin>>tmp){
string input;
//首先将 int 转为 string
while (tmp){
input += (tmp % 10 + '0');
tmp = tmp / 10;
}
reverse(input.begin(), input.end());
//先将数字尾插进去，然后再将数额插入
string output;
//当大于十万时
if (input.size() >= 6){
string cur = input.substr(0, input.size() - 4);
for (int i = 0; i < cur.size(); i++){
if (!((i == cur.size() - 1) && (cur[i] == '0')))
output.push_back(cur[i]);
if (i < cur.size() - 1 && cur[i] != '0')
output.push_back(index[cur.size() - i - 2]);
}
output.push_back('W');
cur = input.substr(input.size() - 4, 4);
for (int i = 0; i < cur.size(); i++){
if (!((i == cur.size() - 1) && (cur[i] == '0')))
output.push_back(cur[i]);
if (i < cur.size() - 1 && cur[i] != '0')
output.push_back(index[cur.size() - i - 2]);
}
}
else if (input.size() <= 5){
for (int i = 0; i < input.size(); i++){
if (!((i == input.size() - 1) && (input[i] == '0')))
output.push_back(input[i]);
if (i < input.size() - 1 && input[i] != '0')
output.push_back(index[input.size() - i - 2]);
}
}
cout << output << endl;
}
*/