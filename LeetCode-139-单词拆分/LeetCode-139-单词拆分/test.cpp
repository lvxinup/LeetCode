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

		//���� unordered_set ���ݴʵ䣬�������Ч��
		//�ҵ����ݴʵ���ַ����ĳ���
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
				//����Ӵ����ȴ���max_size,����
				if ((i - j)>max_size)
					break;

				// F(i): true{j <i && F(j) && substr[j+1,i]���ڴʵ����ҵ�} OR false
				// ��j+1���ַ�������Ϊj
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