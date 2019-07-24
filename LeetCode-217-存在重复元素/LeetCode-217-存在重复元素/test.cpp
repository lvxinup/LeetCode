#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		bool output = false;
		unordered_map<int, int> map;
		for (int i = 0; i<nums.size(); i++){
			map[nums[i]]++;
			if (map[nums[i]] != 1)
				return true;
		}
		return output;
	}
};