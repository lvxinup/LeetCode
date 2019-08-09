#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
using namespace std;

class Solution {
public:
	void digui(vector<string>& output, string tmp, int left, int right){
		if (left > right)	return;
		//递归结束条件
		if (left == 0 && right == 0){
			output.push_back(tmp);
			return;
		}
		else{
			if (left > 0) digui(output, tmp + '(', left - 1, right);
			if (right > 0) digui(output, tmp + ')', left, right - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> output;
		string tmp;//每种有效括号的组合
		int left = n;//表示左括号的数目
		int right = n;//表示右括号的数目
		digui(output, tmp, left, right);
		return output;
	}
};

int main()
{
	Solution s;
	vector<string> output;
	output = s.generateParenthesis(3);
	for (auto& e : output){
		cout << e << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}