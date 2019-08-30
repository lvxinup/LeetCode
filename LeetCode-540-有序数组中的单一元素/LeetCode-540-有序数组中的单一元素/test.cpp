#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0; int right = nums.size() - 1;
		while (left < right){
			int mid = left + (right - left) / 2;
			if (mid % 2 == 1)
				mid--;//保证mid left right 一直都为偶数,就可以根据mid和mid的下一个是否相等判断左右了
			if (nums[mid] == nums[mid + 1]){
				left = mid + 2;
			}
			else
				right = mid;
		}
		return nums[left];
	}
};

int main()
{
	Solution s;
	vector<int> input = { 3, 3, 7, 7, 10, 11, 11 };
	cout << s.singleNonDuplicate(input)<<endl;

	return 0;
}