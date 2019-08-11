#define  _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<iostream>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		//¶þ·Ö²éÕÒ
		int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right) / 2;
		while (left < right){
			if (nums[mid] > target){
				right = mid;
				mid = (left + right) / 2;
			}
			else if (nums[mid] < target){
				left = mid;
				mid = (left + right) / 2;
			}
			else{
				return mid;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 4, 5, 6, 7, 0, 1, 2 };
	cout << s.search(tmp,0) << endl;
	system("pause");
	return 0;
}