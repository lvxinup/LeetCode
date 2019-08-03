#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int left = -1, right = -1;
		vector<int> output;
		for (int i = 0; i<nums.size(); i++){
			if (nums[i] == target){
				left = i;
				break;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--){
			if (nums[i] == target){
				right = i;
				break;
			}
		}
		output.push_back(left);
		output.push_back(right);

		return output;
	}
};