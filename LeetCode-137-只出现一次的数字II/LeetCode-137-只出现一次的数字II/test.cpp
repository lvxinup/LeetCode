#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		if (nums.size() == 1)
			return nums[0];
		int left = 0;
		while (left<nums.size()){
			if (left == nums.size() - 1 && nums[left] != nums[left - 1])
				return nums[left];
			if (nums[left] != nums[left + 1]){
				if (left == 0)
					return nums[left];
				if (nums[left] != nums[left - 1])
					return nums[left];
			}
			left++;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 2, 2, 3, 2 };
	cout << s.singleNumber(tmp) << endl;

	system("pause");
	return 0;
}