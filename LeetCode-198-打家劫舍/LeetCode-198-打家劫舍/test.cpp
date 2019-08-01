#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		//dp[n] = MAX( dp[n-1], dp[n-2] + num )
		vector<int> dp(nums.size() + 1, 0);
		int size = nums.size();
		if (size == 0)   return 0;
		if (size == 1)   return nums[0];
		dp[1] = nums[0];
		for (int i = 2; i <= size; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[size];
	}
};