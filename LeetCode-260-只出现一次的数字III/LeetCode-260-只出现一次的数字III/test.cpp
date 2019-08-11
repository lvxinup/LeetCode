#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//���Ƚ�����������֮����ȵ�Ԫ�ػ����ڡ�
		std::sort(nums.begin(), nums.end());
		vector<int> output;

		if (nums.size() == 2)
			return nums;
		if (nums[0] != nums[1]){
			output.push_back(nums[0]);
		}

		int left = 1;
		while (left<nums.size() - 1){
			//���leftλ��Ϊ�������һ��λ������ǰһ��Ԫ�ز���ȣ���ֱ�ӷ���
			if (left == nums.size() - 1 && nums[left] != nums[left - 1])
				output.push_back(nums[left]);

			//�������߼�����һ��Ԫ��������λ�ö������ʱ��������
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