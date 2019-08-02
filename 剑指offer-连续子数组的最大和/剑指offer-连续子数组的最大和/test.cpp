#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0], max = array[0];
		for (int i = 1; i<array.size(); i++){
			sum += array[i];
			if (sum < array[i]){
				sum = array[i];
			}
			if (sum >= max)
				max = sum;
		}
		return max;
	}
};

int main()
{
	Solution s;
	vector<int> array{1, -2, 3, 10, -4, 7, 2, -5};
	cout << s.FindGreatestSumOfSubArray(array) << endl;
	system("pause");
	return 0;
}