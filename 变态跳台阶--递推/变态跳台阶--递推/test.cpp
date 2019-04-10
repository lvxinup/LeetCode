#define  _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int jumpFloorII(int number) {
		int result = 0;
		if (number == 0 || number == 1)
		{
			return 1;
		}
		int num = number;
		while (num--)
		{
			result = result + jumpFloorII(number - 1);
			number--;
		}
		return result;
	}
};
