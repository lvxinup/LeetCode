#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int lengthOfLastWord(string s) {
		//1.��ָ��
		//2.���ַ���
		//3.ֻ������ĸ "abc"
		//4.������ĸҲ���пո�  "abc "
		//5.������ĸҲ���пո�  "hello world"
		int flag = 0;
		int i = 0;
		if (s.size() == 0)  //��ָ�롢���ַ���
		{
			return 0;
		}
		for (i = 0; i<s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				if (i != 0 && s[i - 1] == ' ')
					flag = 1;
				else
					++flag;
			}
		}
		return flag;
	}
};