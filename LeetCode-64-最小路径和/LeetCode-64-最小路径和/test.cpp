#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int raw = grid.size(), col = grid[0].size();
		vector<vector<int>> output(raw, vector<int>(col, 0));
		output[0][0] = grid[0][0];
		for (int i = 1; i<col; i++){
			output[0][i] = output[0][i - 1] + grid[0][i];
		}
		for (int j = 1; j<raw; j++){
			output[j][0] = output[j - 1][0] + grid[j][0];
		}
		for (int i = 1; i<raw; i++){
			for (int j = 1; j<col; j++){
				output[i][j] = min(output[i - 1][j] + grid[i][j], output[i][j - 1] + grid[i][j]);
			}
		}
		return output[raw - 1][col - 1];
	}
};