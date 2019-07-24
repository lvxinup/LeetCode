#define  _CRT_SECURE_NO_WARNINGS 1

#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		//Ë«Ö¸Õë
		int index = 0;
		for (int i = 0; i<nums.size(); i++){
			if (nums[i] != 0){
				nums[index] = nums[i];
				index++;
			}
		}
		for (int i = index; i<nums.size(); i++){
			nums[i] = 0;
		}
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 0, 1, 0, 3, 12};
	s.moveZeroes(tmp);
	system("pause");
	return 0;
}