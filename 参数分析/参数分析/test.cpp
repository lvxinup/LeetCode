#define  _CRT_SECURE_NO_WARNINGS 1

//�������������������
//xcopy / s c : \ d : \��
//�����������£�
//����1��������xcopy
//����2���ַ��� / s
//����3���ַ���c : \
//����4 : �ַ���d : \
//���дһ��������������ʵ�ֽ������и�����������������
//��������
//1.�����ָ���Ϊ�ո�
//2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy / s ��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files��������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//3.����������
//4.������������֤��������ֲ�����Ҫ�������

#include<string>
#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

int main()
{
	string s;
	vector<string> v;
	int i = 0, flag = 0;    //��־�Ƿ������ų���
	int pos1 = 0, pos2 = 0; 
	int pos;//pos1��ʾ�ո�λ�ã�POS2��ʾ����λ��
	int tmp;
	getline(cin, s);
	while(i<s.size())
	{
		string cur;
		pos = s.find(' ', i);//��pos1λ���ҿո�
		tmp = s.find('"', i);//��pos2��ʼ������
		if (tmp !=string::npos && flag == 0)//�ҵ����ţ�����flagΪ0��˵��֮ǰû������
		{
			pos2 = tmp;
			flag = 1;
			i = tmp+1;
		}
		else if (tmp != string::npos && flag == 1)//�ҵ����ţ�����flagΪ1��˵���ҵ������ڵ��ַ���
		{
			cur = s.substr(i, tmp - i);
			v.push_back(cur);
			i = tmp+1;
		}
		if (pos != string::npos && flag == 1 && pos<tmp)    //�ҵ��ո�,���������Ŵ���
		{
			cur = s.substr(i, pos - i);
			v.push_back(cur);
			i = pos + 1;
		}
		else if (pos != string::npos && flag == 0)    //�ҵ��ո񣬲���û�����Ŵ���
		{
			cur = s.substr(i, pos - i);
			v.push_back(cur);
			i = pos + 1;
		}
		if (pos == string::npos&&tmp == string::npos)//û�пո�û�����ţ�˵��ʣ���һ���ַ���
		{
			cur = s.substr(i, s.size() - i);
			v.push_back(cur);
			break;
		}
	}
	cout << v.size() << endl;
	for (auto& e : v)
		cout << e << endl;

	system("pause");
	return 0;
}