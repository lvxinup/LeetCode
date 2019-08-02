#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	string ReverseSentence(string str) {
		int size = str.size();
		if (size == 0)    return "";
		int begin = 0, end = 0;
		Reverse(str, 0, size - 1);
		while (str[begin] != '\0')
		{
			if (str[begin] == ' ')
			{
				begin++;
				end++;
			}
			else if (str[end] == ' ' || str[end] == '\0')
			{
				Reverse(str, begin, --end);
				end = end + 1;
				begin = end;
			}
			else
			{
				end++;
			}
		}

		return str;
	}
	void Reverse(string&str, int begin, int end)
	{
		while (begin<end)
		{
			swap(str[begin++], str[end--]);
		}
	}
};