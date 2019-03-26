#define  _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1)
			return 0;
		int tmp = 1, left = 0, right = 0;
		int sum = 0;
		while (right<nums.size())
		{
			tmp *= nums[right];
			while (tmp >= k)
			{
				tmp = tmp / nums[left];
				left++;
			}
			sum += right - left + 1;
			right++;
		}
		return sum;
	}
};