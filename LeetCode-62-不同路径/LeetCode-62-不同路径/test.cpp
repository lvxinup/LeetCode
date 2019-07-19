#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1){
			return 0;
		}
		vector<vector<int>> output(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++){

			for (int j = 1; j < n; j++){
				output[i][j] = output[i - 1][j] + output[i][j - 1];
			}
		}
		return output[m - 1][n - 1];
	}
};