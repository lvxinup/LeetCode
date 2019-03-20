#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<string>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = -1, n = s.size();
		//建立字符与出现位置之间的映射。
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			//先找s[i]有没有出现过，出现过就修改left为他上次出现的位置。
			if (m.count(s[i]) && m[s[i]] > left) {
				left = m[s[i]];	//left表示元素上一次出现的位置。
			}
			
			m[s[i]] = i;	
			res = max(res, i - left);//如果left不为-1，说明之前出现过。
									 //如果left为-1，说明之前没出现过，i-left就是i+1。
		}
		return res;
	}
};

int main()
{
	string s = "dvdf";
	Solution S;
	cout << S.lengthOfLongestSubstring(s) << endl;


	system("pause");
	return 0;
}