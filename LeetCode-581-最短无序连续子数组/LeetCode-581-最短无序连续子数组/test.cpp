#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> tmp(nums);
		std::sort(tmp.begin(), tmp.end());
		int left = 0, right = nums.size() - 1;
		for (int i = 0; i<tmp.size(); i++){
			if (tmp[i] == nums[i])
				left++;
			else
				break;
		}
		for (int j = tmp.size() - 1; j >= 0; j--){
			if (tmp[j] == nums[j])
				right--;
			else
				break;
		}
		if (right >= left)
			return right - left + 1;
		else
			return 0;
	}
};