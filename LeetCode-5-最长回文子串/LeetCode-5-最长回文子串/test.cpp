#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())   return "";
		int dp[s.size()][s.size()] = { 0 },left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); i++){
			dp[i][i] = 1;
			for (int j = 0; j < i; j++){
				//当 i = j 时，只有一个字符，肯定是回文串
				//如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]
				//如果i和j不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i + 1][j - 1] 若为真，就是回文串
				dp[j][i] = (s[i] == s[j] && (i - j<2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < right - len + 1){
					left = j;
					right = i;
					len = right - len + 1;
				}
			}
		}
		return s.substr(left, right - left + 1);
	}

};