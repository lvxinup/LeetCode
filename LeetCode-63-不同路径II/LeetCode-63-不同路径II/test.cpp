#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int raw = obstacleGrid.size(), col = obstacleGrid[0].size();
		long long  output[raw][col];
		output[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
		for (int i = 1; i< raw; ++i){
			output[i][0] = obstacleGrid[i][0] == 1 ? 0 : output[i - 1][0];
		}
		for (int j = 1; j< col; ++j){
			output[0][j] = obstacleGrid[0][j] == 1 ? 0 : output[0][j - 1];
		}
		for (int i = 1; i < raw; i++){
			for (int j = 1; j < col; j++){
				output[i][j] = output[i - 1][j] + output[i][j - 1];
				if (obstacleGrid[i][j] == 1)  //说明该位置有障碍
					output[i][j] = 0;
			}
		}
		return output[raw - 1][col - 1];
	}
};