#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> output;
		if (nums.size() == 0)
			return {};
		std::sort(nums.begin(), nums.end());
		int length = nums.size() - 1;
		if (nums[0] <= 0 && nums[length] >= 0){   //数组所有元素同号时，没有满足条件的三元组
			for (int i = 0; i < length - 1; i++){
				if (nums[i] > 0) //数组最左元素大于0时，没有满足条件的三元组
					break;
				int mid = i + 1;
				int right = length;
				if (i > 0 && nums[i] == nums[i - 1])	continue;
				while (mid < right){
					int result = nums[i] + nums[mid] + nums[right];
					if (result == 0){
						vector<int> tmp{ nums[i], nums[mid], nums[right] };
						output.push_back(tmp);
						while (mid < right && nums[mid] == nums[++mid]);
						while (mid < right && nums[right] == nums[--right]);
					}
					else if (result < 0){    //left右移
						while (mid < right && nums[mid] == nums[++mid]);
					}
					else{   //result > 0    right左移
						while (mid < right && nums[right] == nums[--right]);
					}
				}
			}
		}
		return output;
	}
};

int main()
{
	Solution s;
	vector<int> input = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> output;
	output = s.threeSum(input);

	system("pause");
	return 0;
}