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
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());
		digits[0]++;
		for (int i = 0; i<digits.size(); i++){
			if (digits[i] >= 10){
				if (i == (digits.size() - 1)){
					digits[i] -= 10;
					digits.resize(digits.size() + 1);
					digits[i + 1] = 1;
				}
				else{
					digits[i] -= 10;
					digits[i + 1] ++;
				}
			}
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
};

int main()
{
	Solution s;
	vector<int> tmp = { 9 };
	vector<int> output = s.plusOne(tmp);
	for (int i = 0; i < output.size(); i++){
		cout << output[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}