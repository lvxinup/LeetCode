#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))	//	�������к��пո�ʱ��ʹ��cin������ڿո��жϣ���Ҫʹ��getline
	{
		//string newstr;
		size_t pos = str.rfind(' ', str.size());//�ҵ����һ���ո��λ��
		//newstr=str.substr(pos,str.size()-pos);
		cout << str.size() - pos - 1 << endl;
	}
	return 0;
}