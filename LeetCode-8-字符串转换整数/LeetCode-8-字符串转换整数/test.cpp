#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int cur = 0, N = str.size();
		int flag = 1, ret = 0;
		// 1. �����ַ���ǰ��Ŀո�
		while (cur < N && isspace(str[cur])) ++cur;
		// 2(1). �����ڷǿո��ַ�c
		if (cur == N) return 0;
		// 2(2). cΪ'-'
		else if (str[cur] == '-') flag = -1;
		//2(3). cΪ����
		else if (isdigit(str[cur])) ret = str[cur] - '0';
		//2(4). c��Ϊ'+'
		else if (str[cur] != '+') return 0;

		// 3. ��������c����������ַ�
		while (++cur < N && isdigit(str[cur])) {
			int t = (str[cur] - '0') * flag;
			// ����������INT_MAX������INT_MAX
			if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && t > 7) return INT_MAX;
			// ������С��INT_MIN������INT_MIN
			if (ret < INT_MIN / 10 || ret == INT_MIN / 10 && t < -8) return INT_MIN;
			ret = ret * 10 + t;
		}
		return ret;
	}
};


int main()
{
	Solution s;
	cout << s.myAtoi("+   234") << endl;
	system("pause");
	return 0;
}

