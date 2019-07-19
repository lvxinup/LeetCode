#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<vector>
#include<Windows.h>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;
		vector<vector<int>> dp(triangle);
		for (int i = 1; i<triangle.size(); i++){
			for (int j = 0; j <= i; j++){
				//处理左边界和右边界
				if (j == 0){
					dp[i][j] = dp[i - 1][j];
				}
				else if (j == i){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
				}
				dp[i][j] = dp[i][j] + triangle[i][j];
			}
		}
		int result = dp[triangle.size() - 1][0];
		for (int i = 1; i<triangle.size(); i++){
			result = min(result, dp[triangle.size() - 1][i]);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> triangle ={ { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	cout << s.minimumTotal(triangle) << endl;

	system("pause");
	return 0;
}