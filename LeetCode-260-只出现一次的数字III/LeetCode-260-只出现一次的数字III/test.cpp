#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//首先进行排序，排序之后，相等的元素会相邻。
		std::sort(nums.begin(), nums.end());
		vector<int> output;

		if (nums.size() == 2)
			return nums;
		if (nums[0] != nums[1]){
			output.push_back(nums[0]);
		}

		int left = 1;
		while (left<nums.size() - 1){
			//如果left位置为数组最后一个位置且与前一个元素不相等，则直接返回
			if (left == nums.size() - 1 && nums[left] != nums[left - 1])
				output.push_back(nums[left]);

			//正常的逻辑，当一个元素与相邻位置都不相等时，即返回
			if (nums[left] != nums[left + 1]){
				if (left == 0)
					output.push_back(nums[left]);
				if (nums[left] != nums[left - 1])
					output.push_back(nums[left]);
			}
			left++;
		}
		if (output.size() < 2)
			output.push_back(nums[nums.size() - 1]);
		return output;
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 0, 0, 1, 2};

	vector<int> output;
	output = s.singleNumber(tmp);
	for (auto & e : output)
		cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}