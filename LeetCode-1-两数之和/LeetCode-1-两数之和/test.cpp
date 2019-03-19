class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> tmp;
		vector<int> cur;
		for (int i = 0; i < nums.size(); i++)
		{
			tmp[nums[i]] = i;
		}
		for (int i = 0; i<nums.size(); i++)
		{
			int t = target - nums[i];
			if (tmp.count(t) && tmp[t] != i)
			{
				cur.push_back(i);
				cur.push_back(tmp[t]);
				break;
			}
		}
		return cur;
	}

};