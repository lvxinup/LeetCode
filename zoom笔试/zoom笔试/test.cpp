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
//		//首先计算行数，然后判断在奇数行还是偶数行
//		int tmp1 = m / w;
//		int tmp2 = n / w;
//		if (m%w != 0){
//			tmp1++;
//		}
//		if (n%w != 0){
//			tmp2++;
//		}
//		int index1 = m % w;//在行中的位置
//		int index2 = n % w;
//		//奇数行不变，偶数行变位置
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
		//如果是字母，跳过
		if (tmp[i] <='Z' && tmp[i]>='A'){
			continue;
		}
		int flag = 0;
		//如果是数字
		if (tmp[i] <= '9' && tmp[i] >='0'){
			flag = tmp[i] - '0';
		}
		//不断插入字符
		while (flag--){
			tmp += " ";
			//所有元素往后挪
			for (int j = tmp.size() - 1; j >= i; j--){
				tmp[j] = tmp[j - 1];
			}
			//插入元素
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