#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number == 1 || number == 2)
			return number;
		return rectCover(number - 1) + rectCover(number - 2);
	}
};