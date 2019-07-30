#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int climbStairs(int n) {
		vector<int> tmp(10000);
		tmp[1] = 1;
		tmp[2] = 2;
		for (int i = 3; i <= n; i++){
			tmp[i] = tmp[i - 1] + tmp[i - 2];
		}
		return tmp[n];
	}
};