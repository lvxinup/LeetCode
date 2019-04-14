#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

int strtoint(const char* str)	//�ַ���ת��������
{
	//1.��ָ�� str==NULL
	//2.ָ��Ϊ��	str="";
	//3.�Ƿ�����	���š���ĸ����������+-
	//4.ֱ��Ϊ���֣�û�з���

	if (str == NULL && *str == '\0')	//��ָ��&&ָ��Ϊ��
	{
		return -1;
	}
	
	//���е���һ�������ų��˿�ָ��str==NULL��ָ��Ϊ��str=='\0'�������
	int flag = false;
	//�жϵ�һ���ַ�������
	if (*str == '+')	//��һλΪ+
	{
		str++;
	}
	else if (*str == '-')	//��һλΪ-
	{
		flag = true;
		str++;
	}
	long long num = 0;
	while(*str != '\0')	//���û�е��ַ�����β
	{
		if (*str >= '0' && *str < '9')
		{
			int tmp = flag ? -1 : 1;
			num = num * 10 + tmp*(*str - '0');

			//����������Χ
			if ((!flag && num > 0x7FFFFFFF) || (flag && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	return num;
}
int main()
{
	char str = '123';
	cout << strtoint(&str) << endl;
	system("pause");
	return 0;

}