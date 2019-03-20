#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int lengthOfLastWord(string s) {
		//1.空指针
		//2.空字符串
		//3.只含有字母 "abc"
		//4.含有字母也含有空格  "abc "
		//5.含有字母也含有空格  "hello world"
		int flag = 0;
		int i = 0;
		if (s.size() == 0)  //空指针、空字符串
		{
			return 0;
		}
		for (i = 0; i<s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				if (i != 0 && s[i - 1] == ' ')
					flag = 1;
				else
					++flag;
			}
		}
		return flag;
	}
};