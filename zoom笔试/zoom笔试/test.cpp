#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int w, m, n;
//	while (cin >> w >> m >> n){
//		//6 8 2
//		//4
//		//���ȼ���������Ȼ���ж��������л���ż����
//		int tmp1 = m / w;
//		int tmp2 = n / w;
//		if (m%w != 0){
//			tmp1++;
//		}
//		if (n%w != 0){
//			tmp2++;
//		}
//		int index1 = m % w;//�����е�λ��
//		int index2 = n % w;
//		//�����в��䣬ż���б�λ��
//		if (tmp1 % 2 == 0){
//			index1 = w - index1 + 1;
//		}
//		if (tmp2 % 2 == 0){
//			index2 = w - index2 + 1;
//		}
//
//		int output = (tmp1 - tmp2) > 0 ? (tmp1 - tmp2) : (tmp2 - tmp1);
//		output += (index1 - index2) > 0 ? (index1 - index2) : (index2 - index1);
//		cout << output << endl;
//	}
//
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;
std::string mySteryFunc(std::string src)
{
	std::string tmp = src;
	for (int i = 0; i<tmp.size(); i++){
		//�������ĸ������
		if (tmp[i] <='Z' && tmp[i]>='A'){
			continue;
		}
		int flag = 0;
		//���������
		if (tmp[i] <= '9' && tmp[i] >='0'){
			flag = tmp[i] - '0';
		}
		//���ϲ����ַ�
		while (flag--){
			tmp += " ";
			//����Ԫ������Ų
			for (int j = tmp.size() - 1; j >= i; j--){
				tmp[j] = tmp[j - 1];
			}
			//����Ԫ��
			tmp[i] = tmp[i - 1];
		}
	}
	return tmp;
}
int main()
{
	std::string input;
	std::string output;
	std::cin >> input;
	output = mySteryFunc(input);
	std::cout << output << std::endl;
	return 0;
}