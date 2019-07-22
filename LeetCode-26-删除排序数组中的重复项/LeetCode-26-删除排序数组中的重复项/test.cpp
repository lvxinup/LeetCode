#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 1;
		//¿ìÂýÖ¸Õë·¨
		int left = 0, right = 1;
		while (right<nums.size()){
			if (nums[left] == nums[right]){
				right++;
				continue;
			}	
			if (nums[left] != nums[right]){
				left++;
				nums[left] = nums[right];
				right++;
			}
		}
		nums.resize(left + 1);
		return nums.size();
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	cout<<s.removeDuplicates(tmp) << endl;
	system("pause");
	return 0;
}