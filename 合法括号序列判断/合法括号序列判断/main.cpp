#define  _CRT_SECURE_NO_WARNINGS 1

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<int> s;
		for (int i = 0; i<n; i++)
		{
			if (A[i] == '(')
				s.push(1);
			else if (A[i] == ')')
			{
				if (s.size()>0)
					s.pop();
				else
					return false;
			}
		}
		return s.size() == 0;
	}
};