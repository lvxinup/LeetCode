#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int jiecheng(int tmp){
	int output = 1;
	for (int i = tmp; i>0; i--){
		output = output*i;
	}
	return output;
}
int qingkuang(int tmp){
	int output = 0;
	for (int i = tmp - 1; i>0; i--){
		output += i;
	}
	return output;
}
int main()
{
	int input;
	while (cin >> input){
		int output = 0;//����Ԫ�����
		//�����ж�û�еȺŵ����,��input�Ľ׳�
		//��һ���Ⱥŵ����һ���� input-1 �� 1 ���ۼ�
		//��һ���Ⱥŵ���������Խ�n��Ԫ��ת��Ϊn-1��Ԫ�ص�������ϣ��� input-1 �Ľ׳ˡ�
		//�Դ�����
		while (input>1){
			output += qingkuang(input)*jiecheng(input);
			input--;
		}
		cout<<output<<endl;
	}
}