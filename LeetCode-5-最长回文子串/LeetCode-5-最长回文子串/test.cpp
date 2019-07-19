#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())   return "";
		int dp[s.size()][s.size()] = { 0 },left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); i++){
			dp[i][i] = 1;
			for (int j = 0; j < i; j++){
				//�� i = j ʱ��ֻ��һ���ַ����϶��ǻ��Ĵ�
				//��� i = j + 1��˵���������ַ�����ʱ��Ҫ�ж� s[i] �Ƿ���� s[j]
				//���i��j�����ڣ��� i - j >= 2 ʱ�������ж� s[i] �� s[j] ���֮�⣬dp[i + 1][j - 1] ��Ϊ�棬���ǻ��Ĵ�
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