#define  _CRT_SECURE_NO_WARNINGS 1

string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> strs;

		if (digits.empty())
			return strs;

		size_t index = 0;
		string str;

		combineStr(digits, index, str, strs);

		return strs;
	}

	void combineStr(const string& digits, size_t index, const string& str, vector<string>& strs){
		if (str.size() == digits.size()){
			strs.push_back(str);
			return;
		}

		string letters = letterMap[digits[index] - '0'];
		for (size_t i = 0; i < letters.size(); i++){
			combineStr(digits, index + 1, str + letters[i], strs);
		}
	}
};