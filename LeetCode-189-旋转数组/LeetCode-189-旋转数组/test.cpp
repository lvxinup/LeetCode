#define  _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<iostream>
#include<Windows.h>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k > nums.size()) k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 1,2,3,4,5,6 };
	s.rotate(tmp, 2);
	for (int i = 0; i < tmp.size(); i++)
		printf("%d ", tmp[i]);
	cout << endl;
	system("pause");
	return 0;
}