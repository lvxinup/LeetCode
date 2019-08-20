#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> output(T.size(), 0);
		stack<int> s;//创建一个递减栈
		for (int i = T.size() - 1; i >= 0; i--){
			//如果小则入栈
			while (!s.empty() && T[i] >= T[s.top()]){
				s.pop();
			}
			if (s.empty())
				output[i] = 0;
			else
				output[i] = s.top() - i;
			s.push(i);
		}
		return output;
	}
};