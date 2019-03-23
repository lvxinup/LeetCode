#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int strStr(string haystack, string needle) {
		int size1 = haystack.size();
		int size2 = needle.size();
		if (size2 == 0 && size1 == 0)  return 0;
		if (size1 < size2)   return -1;
		for (int i = 0; i <= size1 - size2; i++)
		{
			int j = 0;
			for (j = 0; j<size2; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == size2)
				return i;
		}
		return -1;
	}
};