#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.empty())
			return;
		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin<end)
		{
			swap(s[begin], s[end]);
			begin++;
			end--;
		}

	}
};