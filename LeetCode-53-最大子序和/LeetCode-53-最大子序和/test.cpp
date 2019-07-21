#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int output = INT_MIN, tmp = 0;
		for (int i = 0; i<nums.size(); i++){
			if (tmp<0)
				tmp = 0;
			tmp += nums[i];

			output = max(output, tmp);
		}
		return output;
	}
};

int main()
{
	Solution s;
	vector<int> tmp{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout<<s.maxSubArray(tmp)<<endl;
	system("pause");
	return 0;
}