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
		int output = 0;//所有元素相等
		//首先判断没有等号的情况,即input的阶乘
		//有一个等号的情况一共有 input-1 到 1 的累加
		//有一个等号的情况，可以将n个元素转换为n-1个元素的排列组合，即 input-1 的阶乘。
		//以此类推
		while (input>1){
			output += qingkuang(input)*jiecheng(input);
			input--;
		}
		cout<<output<<endl;
	}
}