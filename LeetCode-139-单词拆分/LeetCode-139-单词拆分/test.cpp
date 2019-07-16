#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
#include<Windows.h>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty())
			return false;
		if (wordDict.empty())
			return false;

		//构建 unordered_set 数据词典，提高搜索效率
		//找到数据词典最长字符串的长度
		unordered_set<string> dict;
		int max_size = 0;
		for (int i = 0; i<wordDict.size(); i++){
			if (wordDict[i].size() >= max_size)
				max_size = wordDict[i].size();
			dict.insert(wordDict[i]);
		}

		vector<bool> output(s.size() + 1, false);
		output[0] = true;
		for (int i = 0; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				//如果子串长度大于max_size,跳过
				if ((i - j)>max_size)
					break;

				// F(i): true{j <i && F(j) && substr[j+1,i]能在词典中找到} OR false
				// 第j+1个字符的索引为j
				if (output[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					output[i] = true;
					break;
				}
			}
		}
		return output[s.size()];
	}
};

int main()
{
	Solution tmp;
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << tmp.wordBreak(s, wordDict) << endl;
	system("pause");
	return 0;
}