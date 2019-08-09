#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int index = -1;
		int tmp = 0;
		bool flag = false;
		for (int i = nums.size() - 1; i>0; i--){
			if (nums[i] <= nums[i - 1]){
				continue;
			}
			else{
				flag = true;
				index = i - 1;
				tmp = nums[i - 1];
				break;
			}
		}
		if (flag == false){
			sort(nums.begin(), nums.end());
			return;
		}
		int i;
		for (i = nums.size() - 1; i>index; i--){
			if (nums[i] > tmp)
				break;
		}
		swap(nums[i], nums[index]);
		reverse(nums.begin() + index + 1, nums.end());
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 5,1,1 };
	s.nextPermutation(tmp);
	for (auto& e : tmp){
		cout << e << " ";
	}
	cout << endl;

	return 0;
}