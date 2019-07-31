#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int minnum = prices[0];
		int output = 0;
		for (int i = 1; i<prices.size(); i++){
			if (prices[i]<minnum){
				//�ݼ�������
				minnum = min(minnum, prices[i]);
				continue;
			}
			//����
			output = max(output, prices[i] - minnum);
		}
		return output;
	}
};