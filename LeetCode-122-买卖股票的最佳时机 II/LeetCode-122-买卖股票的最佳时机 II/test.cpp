#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int max = 0;
		for (int i = 1; i<prices.size(); i++){
			if (prices[i]>prices[i - 1])
				max += prices[i] - prices[i - 1];
		}
		return max;
	}
};