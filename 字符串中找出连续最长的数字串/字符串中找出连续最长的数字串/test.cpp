#define  _CRT_SECURE_NO_WARNINGS 1

//��Ŀ����
//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :
//�������������1������������һ���ַ���str�����Ȳ�����255��
//������� :
//��һ�������str��������������ִ���
//ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
//����
//abcd12345ed125ss123456789
//���
//123456789

#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
int main()
{
	string input;
	string output;
	cin >> input;
	int begin, end;
	int count1, count2;
	for (int cur = 0; cur<input.size();cur++)
	{
		begin = cur;
		end = cur;
		count1 = end - begin;
		while (input[cur] >= '0' && input[cur] <= '9')
		{
			end++;
		}
		count2 = end - begin;;
		if (count2 > count1)
		{
			output = input.substr(begin, end);
		}
		cur++;
	}
	cout << output;
	system("pause");
	return 0;
}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str, res, cur;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++){
//		if (str[i] >= '0' && str[i] <= '9')cur += str[i];
//		else{
//			if (res.length()<cur.length())res = cur;
//			cur = "";
//		}
//	}
//	cout << res;
//	return 0;
//}