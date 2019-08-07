#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;

		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i){
			vv[i - 1].resize(i, 0);
			// 每一行的第一个和最后一个都是1
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}

		for (int i = 0; i<vv.size(); i++){
			for (int j = 0; j<vv[i].size(); j++){
				if (vv[i][j] == 0){
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};