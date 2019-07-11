#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1)
			return true;
		long int i = 1;
		while (i<n)
			i *= 2;
		if (i == n || i * 2 == n)
			return true;
		if (i * 2 > n)
			return false;
		return false;
	}
};