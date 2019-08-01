#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> output(amount + 1, amount + 1);
		output[0] = 0;
		for (int i = 1; i <= amount; i++){
			for (int coin : coins){
				//×´Ì¬×ªÒÆ·½³Ì:output[i] = min(output[i],output[i-coin]+1);
				if (coin <= i)
					output[i] = min(output[i], output[i - coin] + 1);
				else
					continue;
			}
		}
		return output[amount]<amount + 1 ? output[amount] : -1;
	}
};