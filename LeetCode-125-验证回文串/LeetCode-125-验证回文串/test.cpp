#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end){
			//从前往后找第一个数字字符或者字母
			while (begin != end){
				if (IsNumberOrLetter(s[begin])){
					break;
				}
				++begin;
			}

			//从后往前找一个数字字符或者字母
			while (begin < end){
				if (IsNumberOrLetter(s[end])){
					break;
				}
				--end;
			}
			if (begin<end){
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;

				++begin;
				--end;
			}
		}
		return true;
	}

	bool IsNumberOrLetter(char c)
	{
		if (c >= '0' && c <= '9' ||
			c >= 'a' && c <= 'z' ||
			c >= 'A' && c <= 'Z')
		{
			return true;
		}
		return false;
	}
};

