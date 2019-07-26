#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream> 
#include <algorithm>
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
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> output;
		int i = 0, j = 0;
		while ( i<nums1.size()&& j<nums2.size()){
			if (nums1[i]<nums2[j])
				i++;
			else if (nums1[i]>nums2[j])
				j++;
			else{
				output.push_back(nums1[i]);
				i++;
				j++;
			}
		}
		return output;
	}
};

int main()
{
	Solution s;
	vector<int> tmp1 = { 4, 9, 5 };
	vector<int> tmp2 = { 9, 4, 9, 8, 4 };
	vector<int> output = s.intersect(tmp1, tmp2);
	for (int i = 0; i < output.size(); i++){
		cout << output[i] << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}