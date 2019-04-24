#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int jumpFloorII(int number) {
		int result = 1;
		if (number == 0 || number == 1)
			return 1;
		for (int i = 2; i <= number; i++)
		{
			result = result * 2;
		}
		return result;
	}
};
