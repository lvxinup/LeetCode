#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stack>
#include<Windows.h>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		if (s.size() % 2 != 0)
			return false;
		for (int i = 0; i < s.size(); i++){
			//×óÀ¨ºÅÈëÕ»£¬ÓÒÀ¨ºÅ³öÕ»
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				stack.push(s[i]);
				continue;
			}				
			if (s[i] == ')' && stack.size()!=0){
				if (stack.top() == '('){
					stack.pop();
					continue;
				}
				else
					return false;
			}				

			if (s[i] == ']' && stack.size() != 0){
				if (stack.top() == '['){
					stack.pop();
					continue;
				}
				else
					return false;
			}

			if (s[i] == '}' && stack.size() != 0){
				if (stack.top() == '{'){
					stack.pop();
					continue;
				}
				else
					return false;
			}

		}
		if (stack.size() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	string tmp = "()[]{}";
	cout<<s.isValid(tmp)<<endl;
	system("pause");
	return 0;
}