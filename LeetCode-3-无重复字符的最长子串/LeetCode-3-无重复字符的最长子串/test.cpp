#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<string>
#include<Windows.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, left = -1, n = s.size();
		//�����ַ������λ��֮���ӳ�䡣
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			//����s[i]��û�г��ֹ������ֹ����޸�leftΪ���ϴγ��ֵ�λ�á�
			if (m.count(s[i]) && m[s[i]] > left) {
				left = m[s[i]];	//left��ʾԪ����һ�γ��ֵ�λ�á�
			}
			
			m[s[i]] = i;	
			res = max(res, i - left);//���left��Ϊ-1��˵��֮ǰ���ֹ���
									 //���leftΪ-1��˵��֮ǰû���ֹ���i-left����i+1��
		}
		return res;
	}
};

int main()
{
	string s = "dvdf";
	Solution S;
	cout << S.lengthOfLongestSubstring(s) << endl;


	system("pause");
	return 0;
}