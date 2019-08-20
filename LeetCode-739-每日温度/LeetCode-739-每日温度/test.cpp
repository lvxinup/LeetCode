#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> output(T.size(), 0);
		stack<int> s;//����һ���ݼ�ջ
		for (int i = T.size() - 1; i >= 0; i--){
			//���С����ջ
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